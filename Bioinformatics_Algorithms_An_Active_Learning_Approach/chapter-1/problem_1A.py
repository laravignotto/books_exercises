'''
Code Challenge: Implement PatternCount.
    Input: Strings Text and Pattern.
    Output: Count(Text, Pattern).
'''
from utils import *


def pattern_count(text, pattern):
    '''Counts the number of occurrencies of `pattern in `text`
    
    Parameters
    ----------
    text : str
        Input text
    pattern : str
        String of text to find in `text`

    Returns
    -------
    count : int
        Number of times that `pattern` appears in `text`
    '''

    count = 0
    for i in range(len(text)-len(pattern)):
        if text[i:len(pattern)+i] == pattern:
            count += 1
    return count


def main():
    txt = import_txt("Vibrio_cholerae")[0]
    pat = input("Insert a string and press Enter: ")
    n = pattern_count(txt, pat)
    print(f"The string {pat} appers {n} times in the text.")


if __name__ == "__main__":
    main()
