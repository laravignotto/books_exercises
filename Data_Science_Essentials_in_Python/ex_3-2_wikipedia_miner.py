'''
program that reports ten most frequently used stems 
in the Wikipedia page titled ''Data science''
'''
import requests
import json
import html2text
from collections import Counter
import nltk
# nltk.download('punkt')
# nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk import LancasterStemmer

# Parse the content of a page using MediaWiki API
S = requests.Session()

URL = "https://en.wikipedia.org/w/api.php"

TITLE = "Data science"

PARAMS = {
    'action': "parse",
    'page': TITLE,
    'format': "json"
}

R = S.get(url=URL, params=PARAMS)
DATA = R.json()

# get the text
wiki_page_text = DATA["parse"]["text"]["*"]

h = html2text.HTML2Text()
h.ignore_links = True
page_text = h.handle(wiki_page_text)

# create a new stemmer
ls = LancasterStemmer()

# tokenize text
words = nltk.word_tokenize(page_text)

words = [w.lower() for w in words]

# eliminate stop words and stem the rest of the words
words = [ls.stem(w) for w in words if w not in stopwords.words("english") and w.isalnum()]

freqs = Counter(words)

print("The 10 most frequently used stems in the ''Data science'' Wikipedia page are:")
for word, count in freqs.most_common(10):
    print(word, count)
