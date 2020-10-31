from datetime import datetime

NEW_LINE = "<new_line>"
FILE_INPUT = "word_order.txt"
FILE_OUTPUT = "law.txt"


def get_data():
    """
    Reads the data from input file
    and returns list of tuples containing
    each line splitted by a space.
    """

    data = []

    with open(FILE_INPUT, encoding="utf8") as input:
        for line in input:
            split = line.split()
            data.append((int(split[0]), split[1]))

    return data


def save_data(data):
    """
    Saves a list of strings to a file.
    Before saving it converts "<new_line>"
    to "\n".

    Keyword arguments:
    data -- the list of strings
    """

    with open(FILE_OUTPUT, "w+", encoding="utf8") as output:
        for item in data:
            if item == NEW_LINE:
                item = "\n"
            else:
                item += " "

            output.write(item)


def sort(list):
    """
    Sorts a list of tuples containing
    order and string.

    How does it work?
    1/ get count of each rank
    2/ create dict containing starting index for each rank
    3/ assign items to list

    Keyword arguments:
    list -- the list of tuples
    """

    output = [None] * len(list)
    counts = {}

    # print("counting . . .")

    for item in list:
        counts[item[0]] = 1 + counts.get(item[0], 0)

    indexes = {}
    i = 0
    j = 0
    shift = 0

    # print("indexing . . .")

    while j != len(counts):
        if i in counts:
            indexes[i] = shift
            shift += counts[i]
            j += 1

        i += 1

    # print("sorting . . .")

    for item in list:
        output[indexes[item[0]]] = item[1]
        indexes[item[0]] += 1

    return output


read_start = datetime.now()

list = get_data()

start = datetime.now()
print("Reading:", start - read_start)

sorted = sort(list)

end = datetime.now()
print("Sorting:", end - start)

save_data(sorted)

write_end = datetime.now()
print("Writing:", write_end - end)
print("TOTAL:", write_end - read_start)
