from datetime import datetime

NEW_LINE = "<new_line>"
FILE_INPUT = "word_order.txt"
FILE_OUTPUT = "law.txt"

def get_data():
    data = []

    with open(FILE_INPUT, encoding="utf8") as input:
        for line in input:
            split = line.split()
            data.append((int(split[0]), split[1]))

    return data

def save_data(data):
    with open(FILE_OUTPUT, "a+") as output:
        for item in data:
            if item == NEW_LINE:
                item = "\n"

            output.append(item)

read_start = datetime.now()
list = get_data()
start = datetime.now()
print(start - read_start)
print(start)

output = []
counts = {}

print("counting . . .")

for item in list:
    key = item[0]
    counts[key] = 1 + counts.get(key, 0)
    output.append(None)

indexes = {}
i = 0
j = 0
shift = 0

print("indexing . . .")

while j != len(counts):
    if i in counts:
        indexes[i] = shift
        shift += counts[i]
        j += 1
    
    i += 1

print("sorting . . .")

for item in list:
    index = indexes[item[0]]
    output[index] = item[1]
    indexes[item[0]] += 1

end = datetime.now()
print(end)
print(end - start)

save_data(output)

# get count of each rank
# create list of size of sum of counts of ranks
# create dict containing starting index for each rank
# assign items to list
