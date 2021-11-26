'''
Frequent Words Problem: Find the most frequent k-mers in a string.
    Input: A string Text and an integer k.
    Output: All most frequent k-mers in Text.
'''
from tqdm import tqdm

from utils import *
from problem_1A import *    # pattern_count
from problem_1L import *    # pattern_to_number
from problem_1M import *    # number_to_pattern


def frequent_words(text, k):
    '''(Slowly) finds the most frequent k-mer in `text`

    Parameters
    ----------
    text : str
        Input text
    k : int
        Length of the k-mer

    Returns
    -------
    frequent_patterns : set
        The most frequent string(s) of length k that appear in `text`
    '''

    frequent_patterns = []
    count = [0] * (len(text)-k+1)
    for i in tqdm(range(len(text)-k+1)):
        pattern = text[i:k+i]
        count[i] += pattern_count(text, pattern)
    max_count = max(count)
    for i in range(len(text)-k+1):
        if count[i] == max_count:
            frequent_patterns.append(text[i:k+i])
    return set(frequent_patterns)


def computing_frequencies(text, k):
    '''Generates a frequency array

    Parameters
    ----------
    text : str
        Input text
    k : int
        Length of the k-mer (pattern)

    Returns
    -------
    frequentcy_array : list
        Array in which every element is an integer denoting how many
        times each pattern of length `k` (specified by the index of the
        array) appears in `text`
    '''

    frequency_array = [0] * 4**k
    for i in tqdm(range(len(text)-k+1)):
        pattern = text[i:k+i]
        j = pattern_to_number(pattern)
        frequency_array[j] += 1

    return frequency_array


def faster_frequent_words(text, k):
    '''Finds the most frequent k-mer in `text`

    Parameters
    ----------
    text : str
        Input text
    k : int
        Length of the k-mer

    Returns
    -------
    frequent_patterns : set
        The most frequent string(s) of length k that appear in `text`
    '''

    frequent_patterns = []
    frequency_array = computing_frequencies(text, k)
    max_count = max(frequency_array)
    for i in range(len(frequency_array)):
        if frequency_array[i] == max_count:
            pattern = number_to_pattern(i,k)
            frequent_patterns.append(pattern)

    return set(frequent_patterns)


def main():
    # txt = import_txt("Vibrio_cholerae")[0]
    # txt = "ACTGACTCCCACCCC"  # k = 3 -> 'CCC'
    # txt = "ACAACTATGCATACTATCGGGAACTATCCT"  # k = 5 -> 'ACTAT'
    # txt = "CGATATATCCATAG"  # k = 3 -> 'ATA'
    txt = "ATCAATGATCAACGTAAGCTTCTAAGCATGATCAAGGTGCTCACACAGTTTATCCACAACCTGAGTGGATGACATCAAGATAGGTCGTTGTATCTCCTTCCTCTCGTACTCTCATGACCACGGAAAGATGATCAAGAGAGGATGATTTCTTGGCCATATCGCAATGAATACTTGTGACTTGTGCTTCCAATTGACATCTTCAGCGCCATATTGCGCTGGCCAAGGTGACGGAGCGGGATTACGAAAGCATGATCATGGCTGTTGTTCTGTTTATCTTGTTTTGACTGAGACTTGTTAGGATAGACGGTTTTTCATCACTGACTAGCCAAAGCCTTACTCTGCCTGACATCGACCGTAAATTGATAATGAATTTACATGCTTCCGCGACGATTTACCTCTTGATCATCGATCCGATTGAAGATCTTCAATTGTTAATTCTCTTGCCTCGACTCATAGCCATGATGAGCTCTTGATCATGTTTCCTTAACCCTCTATTTTTTACGGAAGAATGATCAAGCTGCTGCTCTTGATCATCGTTTC"    # oriC of Vibrio Cholerae

    k = int(input("Insert a number `k`: "))
    print("Searching...")

    # Uncomment just one of the lines below
    # fp = frequent_words(txt, k)  # WARNING: inefficient
    fp = faster_frequent_words(txt, k)

    print(
        f"The most frequent pattern(s) of length {k} that appear(s) in the text is/are:")
    for i in fp:
        print(i)


if __name__ == "__main__":
    main()
