'''
Program that indexes all files in a user-specified directory
and saves the result in a pickled file
'''
import os
import glob
import re
import pickle
import traceback

path = input("Give me the path to the desired directory (e.g.:/home/user/.../): ")

# Creates a list of the files' names in the current directory
list_of_files = [(os.path.basename(x)) for x in glob.glob(path+"*")]

# Creates a dictionary in which keys are all the unique words in every
# file, and values are the names of the files that contain that word
words_in_files = {}

for file in list_of_files:
    try:
        with open(path + file, "r") as f:
            file_content = f.read()
            words = re.findall(r"\w+", file_content)
            single_words = set(words)
            for word in single_words:
                if word not in words_in_files:
                    words_in_files[word] = [file]
                else:
                    words_in_files[word].append(file)
    except:
        # Ignores unsuitable files (e.g.: directories, images, pdfs, ...)
        pass

# Saves the dictionary in a file
filename = "indexed_files.pickle"
with open(filename, "wb") as f:
    pickle.dump(words_in_files, f)
