"""
N-ary heap implementation.
"""


class NHeap(object):
    """
    Class representing a maximum n-ary heap.
    """

    def __init__(self, n, hl=None):
        """
        Build heap from list. O(n).

        Keyword arguments:
        n -- maximum number of children each (sub)tree can have
        hl -- a list of values
        """

        if n < 1:
            raise ValueError("Parameter 'n' must be greater than zero.")

        self.__n = n
        self._hl = [] if hl is None else hl[:]

        for i in range(self._parent(self.size() - 1), -1, -1):
            self.__heapify(i)

    def get_n(self):
        """
        Get maximum number of children each (sub)tree can have. O(1).
        """
        return self.__n

    def get_max(self):
        """
        Get maximum item, do not remove it. O(1).
        """
        return self._hl[0] if self.size() > 0 else None

    def extract_max(self):
        """
        Get maximum item and remove it. O(log n).
        """
        max = self.get_max()

        if max is not None:
            last = self._hl.pop()

            if self.size() > 0:
                self._hl[0] = last
                self.__heapify(0)

        return max

    def insert(self, value):
        """
        Insert new item into heap. O(log n).

        Keyword arguments:
        value -- the value to insert
        """
        self._hl.append(value)
        i = self.size() - 1

        while i > 0 and self._hl[self._parent(i)] < self._hl[i]:
            parent = self._parent(i)
            self._hl[parent], self._hl[i] = self._hl[i], self._hl[parent]

            i = parent

    def size(self):
        """
        Get size of heap. O(1).
        """
        return len(self._hl)

    def __heapify(self, i):
        max = None

        for child in self._children(i):
            if max is None or self._hl[max] < self._hl[child]:
                max = child

        # _children(i) returned blank range
        if max is None:
            return

        if self._hl[i] < self._hl[max]:
            self._hl[i], self._hl[max] = self._hl[max], self._hl[i]
            self.__heapify(max)

    def _children(self, i):
        """
        Get range of indexes of children of specified index. O(1).

        Keyword arguments:
        i -- index whose children should be returned
        """
        first_child = (self.__n * i) + 1

        if first_child >= self.size():
            return range(0, 0)

        last_child = (self.__n * i) + self.__n

        if last_child >= self.size():
            last_child = self.size() - 1

        return range(first_child, last_child + 1)

    def _parent(self, i):
        """
        Get index of parent to the specified index. O(1).

        Keyword arguments:
        i -- index whose parent should be returned
        """
        return (i - 1) // self.__n


def run_tests():
    """
    Run some tests on NHeap
    """

    def print_children(nheap):
        print("children: ", end=" ")

        for child in nheap._hl:
            print(child, end=", ")

        print()

    def print_max(nheap):
        print("max: ", nheap.get_max())

    def print_children_indexes(nheap, i):
        print("children indexes: ", end=" ")

        for x in nheap._children(i):
            print(x, end=", ")

        print()

    def print_parent(nheap, i):
        print("parent for ", i, ": ", nheap._parent(i))

    try:
        NHeap(-17)
    except ValueError:
        print("Successful crash")

    try:
        NHeap(0)
    except ValueError:
        print("Successful crash")

    NHeap(1)  # no crash

    print_children(NHeap(4))  # nothing
    print_children(NHeap(4, []))  # nothing
    print_children(NHeap(4, [0]))  # 0
    print_children(NHeap(4, [0, 1]))  # 1, 0
    print_children(NHeap(4, [0, 1, 2, 3, 4]))  # 4, 1, 2, 3, 0
    print_children(NHeap(4, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    # - 10, 8, 9, 3, 4, 5, 6, 7, 1, 0, 2

    print_children_indexes(NHeap(4), 0)  # nothing
    print_children_indexes(NHeap(4, []), 0)  # nothing
    print_children_indexes(NHeap(4, [0]), 0)  # nothing
    print_children_indexes(NHeap(4, [0, 1]), 0)  # 1
    print_children_indexes(NHeap(4, [0, 1, 2, 3, 4]), 0)
    # - 1, 2, 3, 4
    print_children_indexes(NHeap(4, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 0)
    # - 1, 2, 3, 4
    print_children_indexes(NHeap(4, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 1)
    # - 5, 6, 7, 8
    print_children_indexes(NHeap(4, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 2)
    # - 9, 10

    print(NHeap(17).get_n())  # 17
    print(NHeap(4, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]).size())  # 11

    print_max(NHeap(4))  # None
    print_max(NHeap(4, []))  # None
    print_max(NHeap(4, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))  # 10

    print_parent(NHeap(4), 1)  # 0
    print_parent(NHeap(4, []), 2)  # 0
    print_parent(NHeap(4, [1, 2, 3]), 5)  # 1
    print_parent(NHeap(4), 8)  # 1
    print_parent(NHeap(4), 9)  # 2
    print_parent(NHeap(4), 10)  # 2

    nheap = NHeap(4, [0, 1, 2])
    print(nheap.get_max())  # 2
    print(nheap.extract_max())  # 2
    print(nheap.extract_max())  # 1
    nheap.insert(10)
    print(nheap.extract_max())  # 10
    print(nheap.extract_max())  # 0
    print(nheap.extract_max())  # None
    nheap.insert(10)
    nheap.insert(17)
    print(nheap.extract_max())  # 17
    print(nheap.extract_max())  # 10
    print(nheap.extract_max())  # None


# run_tests()
