def try_get_item(list, index):
    """
    Returns an item from a list on the specified index.
    If index is out or range, returns `None`.

    Keyword arguments:
    list -- the list
    index -- the index of the item
    """
    return list[index] if index < len(list) else None


def union(A, B):
    """
    Returns a union of two lists.

    Keyword arguments:
    A -- the first list
    B -- the second list
    """

    ia = 0
    ib = 0
    output = []

    while ia < len(A) or ib < len(B):
        a = try_get_item(A, ia)
        b = try_get_item(B, ib)

        if a is None or (b is not None and a > b):
            # Don't add duplicates
            if len(output) == 0 or b != output[-1]:
                output.append(b)

            ib += 1
        elif b is None or a < b:
            # Don't add duplicates
            if len(output) == 0 or a != output[-1]:
                output.append(a)

            ia += 1
        elif a == b:
            # Don't add duplicates
            if len(output) == 0 or a != output[-1]:
                output.append(a)

            ia += 1
            ib += 1

    return output


def intersection(A, B):
    """
    Returns an intersection of two lists.

    Keyword arguments:
    A -- the first list
    B -- the second list
    """

    ia = 0
    ib = 0
    output = []

    while ia < len(A) and ib < len(B):
        a = A[ia]
        b = B[ib]

        if a == b:
            # Don't add duplicates
            if len(output) == 0 or a != output[-1]:
                output.append(a)

            ia += 1
            ib += 1
        elif a < b:
            ia += 1
        else:  # if a > b:
            ib += 1

    return output


def relative_complement(A, B):
    """
    Returns a relative complement of two lists (B in A).

    Keyword arguments:
    A -- the first list
    B -- the second list
    """

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
            # Don't add duplicates
            if len(output) == 0 or a != output[-1]:
                output.append(a)

            ia += 1
        else:  # if a > b:
            ib += 1

    return output


# Tests
"""
l = [1, 2, 3]
r = [1, 2, 4, 5]
e = []

print("union")
print(union(l, l))
print(union(l, r))
print(union(l, e))
print(union(r, l))
print(union(r, r))
print(union(r, e))
print(union(e, l))
print(union(e, r))
print(union(e, e))

print("intersection")
print(intersection(l, l))
print(intersection(l, r))
print(intersection(l, e))
print(intersection(r, l))
print(intersection(r, r))
print(intersection(r, e))
print(intersection(e, l))
print(intersection(e, r))
print(intersection(e, e))

print("relative_complement")
print(relative_complement(l, l))
print(relative_complement(l, r))
print(relative_complement(l, e))
print(relative_complement(r, l))
print(relative_complement(r, r))
print(relative_complement(r, e))
print(relative_complement(e, l))
print(relative_complement(e, r))
print(relative_complement(e, e))

print("duplicates")
print(union([1, 2, 2, 3, 3], [1, 1, 2, 2, 3]))
print(intersection([1, 1, 2, 2, 3, 3], [1, 1, 2, 2, 3, 3]))
print(relative_complement([1, 1, 2, 2, 3, 3], []))
"""
