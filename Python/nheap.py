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

        for i in range(round(self.size() / n) - 1, -1, -1):
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

        if max is None:
            return

        if self._hl[i] < self._hl[max]:
            self._hl[i], self._hl[max] = self._hl[max], self._hl[i]
            self.__heapify(max)

    def _children(self, i):
        """
        Get range of indexes of children of specified index.
        O(n) where n is maximum number of children each (sub)tree can have.
        """
        first_child = (self.__n * i) + 1

        if first_child >= self.size():
            return range(0, 0)

        last_child = (self.__n * i) + self.__n

        while last_child >= self.size():
            last_child -= 1

        return range(first_child, last_child + 1)

    def _parent(self, i):
        """
        Get index of parent to the specified index. O(1).
        """
        return (i - 1) // self.__n
