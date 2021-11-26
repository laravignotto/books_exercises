def import_txt(filename):
    with open(f"{filename}.txt", "r") as f:
        return f.readlines()