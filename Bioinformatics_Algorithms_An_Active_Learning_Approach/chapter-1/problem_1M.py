def number_to_symbol(index):
    if index == 0:
        return "A"
    elif index == 1:
        return "C"
    elif index == 2:
        return "G"
    elif index == 3:
        return "T"
    else:
        print("Incorrect index. Must be either 0, 1, 2 or 3")


def number_to_pattern(index, k):
    '''Converts an index into a pattern of length `k`. The index 
    represents the place of the pattern in a list of all the 
    lexicographically ordered patterns of the same length
    
    Parameters
    ----------
    index : int
        Place of the pattern in a list of all the lexicographically
        ordered patterns of the same length
    k : int
        Length of the pattern

    Returns
    -------
    _ : str
        DNA string of length `k`
    '''

    if k == 1:
        return number_to_symbol(index)
    prefix_index = index // 4
    r = index % 4
    symbol = number_to_symbol(r)
    prefix_pattern = number_to_pattern(prefix_index, k-1)

    return prefix_pattern + symbol


def main():
    idx = int(input("Insert an index (integer) and press Enter: "))
    k = int(input("Insert the length of the string `k` (integer) and press Enter: "))
    pat = number_to_pattern(idx, k)
    print(f"The pattern of length {k} with index {idx} is {pat}.")


if __name__ == "__main__":
    main()
