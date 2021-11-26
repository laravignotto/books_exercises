def symbol_to_number(symbol):
    if symbol == "A":
        return 0
    elif symbol == "C":
        return 1
    elif symbol == "G":
        return 2
    elif symbol == "T":
        return 3
    else:
        print("Incorrect symbol. Must be either 'A', 'C', 'G' or 'T'")


def pattern_to_number(pattern):
    '''Converts a DNA string, a `pattern`, into a number that represents
    its place (or index) in a list of all the lexicographically ordered 
    patterns of the same length
    
    Parameters
    ----------
    pattern : str
        DNA string

    Returns
    -------
    _ : int
        Number that represents the "place" in which `pattern` is in a list
        of all the lexicographically ordered patterns of the same length
    '''

    if len(pattern) == 0:
        return 0
    symbol = pattern[-1]
    prefix = pattern[:-1]
    
    return 4 * pattern_to_number(prefix) + symbol_to_number(symbol)


def main():
    pat = input("Insert a string and press Enter: ")
    n = pattern_to_number(pat)
    print(f"The string '{pat}' corresponds to the number {n}.")


if __name__ == "__main__":
    main()
