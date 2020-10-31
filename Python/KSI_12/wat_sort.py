from datetime import datetime

class wut(object):
    def __init__(self, n, c):
        self.number = n
        self.content = c
    
    def __str__(self):
        return str(self.content)

    def __repr__(self):
        return str(self)

def wat_sort(list):
    start = datetime.now()

    counts = {}
    output = []

    for item in list:
        key = item.number
        counts[key] = 1 + counts.get(key, 0)
        output.append(None)
    
    indexes = {}
    i = 0
    j = 0
    shift = 0

    while j != len(counts):
        if i in counts:
            indexes[i] = shift
            shift += counts[i]
            j += 1
        
        i += 1

    for item in list:
        index = indexes[item.number]
        output[index] = item.content
        indexes[item.number] += 1
    
    end = datetime.now()
    print(end - start)
    return output

# get count of each rank
# create list of size of sum of counts of ranks
# create dict containing starting index for each rank
# assign items to list