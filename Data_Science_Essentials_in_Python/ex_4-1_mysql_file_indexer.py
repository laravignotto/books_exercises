'''
This program takes a file in input, and for each word in the file
records the word itself, its ordinal number in the file, and the 
part-of-speech marker in a MySQL database.

The starting table is the following:
CREATE TABLE words (ordnum INT PRIMARY KEY AUTO_INCREMENT, word TINYTEXT NOT NULL, posmarker TINYTEXT);
'''
import pymysql.cursors
import nltk
from nltk.tokenize import WordPunctTokenizer

# get all the words in the document
file = input("What's the file name (with extension) in this folder you want to index?\n")

with open(file, "r") as doc:
    text = doc.read()
    #tokenize text
    word_punct = WordPunctTokenizer()
    tokenized_text = word_punct.tokenize(text)
    #pos tag each word
    pos_marked_text = nltk.pos_tag(tokenized_text)

#change according to your data
connection = pymysql.connect(host="localhost", 
                            user="user", 
                            password="pwd", 
                            db="mydb")
cursor = connection.cursor()

#insert ordinal number, word, and pos tag into the table
for word, pos in pos_marked_text:
    sql = "INSERT INTO words VALUES (NULL, %s, %s)"
    cursor.execute(sql, (word, pos))
    
connection.commit()

#select and display table
query = "SELECT * FROM words"
n_rows = cursor.execute(query)

results = list(cursor.fetchall())

print(results)
connection.close()
