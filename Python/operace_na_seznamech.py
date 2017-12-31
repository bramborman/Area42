def try_get_item(list, index):
    return list[index] if index < len(list) else None


def union(A, B):
    ia = 0
    ib = 0
    output = []

    while ia < len(A) or ib < len(B):
        a = try_get_item(A, ia)
        b = try_get_item(B, ib)

        if a is None or (b is not None and a > b):
            output.append(b)
            ib += 1
        elif b is None or a < b:
            output.append(a)
            ia += 1
        elif a == b:
            output.append(a)
            ia += 1
            ib += 1

    return output


def intersection(A, B):
    ia = 0
    ib = 0
    output = []

    while ia < len(A) and ib < len(B):
        a = try_get_item(A, ia)
        b = try_get_item(B, ib)

        if a == b:
            output.append(a)
            ia += 1
            ib += 1
        elif a < b:
            ia += 1
        else:  # if a > b:
            ib += 1

    return output


def relative_complement(A, B):
    ia = 0
    ib = 0
    output = []

    while ia < len(A):
        a = try_get_item(A, ia)
        b = try_get_item(B, ib)

        if a == b:
            ia += 1
            ib += 1
        elif b is None or a < b:
            output.append(a)
            ia += 1
        else:  # if a > b:
            ib += 1

    return output


# Tests
# print(union([1, 2, 3], [1, 2, 4, 5]))
# print(union([1, 2, 4, 5], [1, 2, 3]))
# print(intersection([1, 2, 3], [1, 2, 4, 5]))
# print(intersection([1, 2, 4, 5], [1, 2, 3]))
# print(relative_complement([1, 2, 3], [1, 2, 4, 5]))
# print(relative_complement([1, 2, 4, 5], [1, 2, 3]))
