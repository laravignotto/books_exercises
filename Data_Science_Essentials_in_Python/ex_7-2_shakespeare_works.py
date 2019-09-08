'''
Program that creates a network of all Shakespeare's plays and the 
100 top-most frequently used non–stop word stems. The program then 
identifies network communities and reports the modularity and the 
member nodes by community.
'''
import networkx as nx
import community
import pandas as pd 
from urllib.request import urlopen
from urllib.parse import urljoin
from bs4 import BeautifulSoup
from collections import Counter
from nltk.corpus import stopwords
from nltk import LancasterStemmer
from nltk import word_tokenize
import os

def extractLinksFromPage(page_url):
    '''
    Given the link of a webpage (string), returns a list of 
    tuples of the name and url of all the links in the page:
    [('name1', 'url1'), ('name2', 'url2'), ...]
    '''
    if page_url[:4] == "http":
        pass
    else:
        page_url = "http://" + page_url

    with urlopen(page_url) as infile:
        soup = BeautifulSoup(infile, features="lxml")

    links = [(link.string, link["href"]) for link in soup.find_all("a") if link.has_attr("href")]

    return links

def getStemsFromURL(page_url):
    '''
    Given the link of a webpage (string), returns a list of 
    all the words' stems in the webpage text
    '''
    with urlopen(page_url) as infile:
        soup = BeautifulSoup(infile, features="lxml")

    ls = LancasterStemmer()
    words = word_tokenize(soup.text)
    words = [w.lower() for w in words]
    words = [ls.stem(w) for w in words if w not in stopwords.words("english") and w.isalpha()]
    return words

def getMostUsedWordsTxt(file, wordnum):
    '''
    Given a text file name (string) and the number of most
    used words we want to find (int), returns a list of the wordnum
    most common elements and their counts from the most common
    to the least:
    [('1st_most_common_word', count1), 
    ('2nd_most_common_word', count2), 
    ...,
    ('wordnumth_most_common_word', countwordnum)]
    '''
    with open(file, "r") as f:
        words = f.read()
        words = words.split()

    ls = LancasterStemmer()
    words = [w.lower() for w in words]
    words = [ls.stem(w) for w in words if w not in stopwords.words("english") and w.isalpha()]
    freqs = Counter(words)
    return freqs.most_common(wordnum)

def copyAllPlaysTextInFile(filename, df, colname):
    '''
    Given a txt file name, a data frame, and the name of the 
    column with the links, copies all text in the links pages 
    into the txt file
    '''
    with open(filename, 'a') as f:
        for index, row in df.iterrows():
            response = urlopen(row[colname])
            soup = BeautifulSoup(response, features="lxml")
            words = word_tokenize(soup.text)
            for word in words:
                f.write(word+' ')

def generateGraph(graph, df, colname_links, colname_titles, listwords):
    '''
    Given a networkx graph, a data frame, the name of the 
    column containing the links, the name of the column 
    containing the plays' titles, and a list of most used 
    words, generates a graph in which a stem and a play are 
    connected if the stem is used in the play, and the 
    weight of the edge equals the frequency of use
    '''
    for index, row in df.iterrows():
        stems = getStemsFromURL(row[colname_links])
        freqs = Counter(stems)
        for word in listwords:
            if word[0] in stems:
                weight = freqs[word[0]]
                G.add_edge(row[colname_titles], word[0], weight=weight)
    
    return G

if __name__ == "__main__":
    print("\nPlease wait, this may take a few minutes.\n")

    # Get the title and link of every Shakespeare's play (minus poems)
    base = "http://shakespeare.mit.edu"
    plays_links = extractLinksFromPage(base)
    plays_links = plays_links[2:-2]
    plays_links = [(title.strip('\n'), urljoin(base, link.replace("index", "full"))) for (title, link) in plays_links if 'Poetry' not in link]

    # Frame with 2 columns: 'Title' of the play, and 'Link' to the full text
    plays = pd.DataFrame(plays_links, columns=('Title','Link'))

    # Copy every play's text in a file
    print("Writing all plays in file...\n")
    copyAllPlaysTextInFile("allplays.txt", plays, 'Link')

    # Get the 100 most frequent words in all Shakespeare's plays
    print("Getting the top 100 most used word stems in all Shakespeare's plays...\n")
    most_used_top_100 = getMostUsedWordsTxt("allplays.txt", 100)
    os.remove("allplays.txt")

    # Build the graph
    print("Generating the graph...\n")
    G = nx.Graph()
    G = generateGraph(G, plays, 'Link', 'Title', most_used_top_100)

    # Get communities with member nodes, and modularity
    print("Calculating communities...")
    partition = community.best_partition(G)

    for comm in set(partition.values()):
        print("\nCommunity %d" % comm)
        print(', '.join([node for node in partition if partition[node] == comm]))

    print("\nModularity: %s\n" % community.modularity(partition, G))
