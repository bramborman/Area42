"""N-ary heap implementation."""

class NHeap(object):
    """Represents a maximum n-ary heap."""

    def __init__(self, n, hl=None):
        """Build heap from list. O(n)."""
        self.__n = n
        self._hl = [] if hl == None else hl[:]

        for i in range(round(self.size() / n) - 1, -1, -1):
            self.__heapify(i)
    
    def get_n(self):
        """Get maximum number of children each (sub)tree can have. O(1)."""
        return self.__n

    def get_max(self):
        """Get maximum item, do not remove it. O(1)."""
        return self._hl[0] if self.size() > 0 else None

    def extract_max(self):
        """Get maximum item and remove it. O(???)."""
        max = self.get_max()

        if max != None:
            last = self._hl.pop()

            if self.size() > 0:
                self._hl[0] = last
                self.__heapify(0)

        return max

    def insert(self, value):
        """Insert new item into heap. O(???)."""
        self._hl.append(value)
        i = self.size() - 1

        while i >= 0 and self._hl[self.__parent(i)] < self._hl[i]:
            self._hl[self.__parent(i)], self._hl[i] = self._hl[i], self._hl[self.__parent(i)]
            self.__heapify(i)
            i = self.__parent(i)

    def size(self):
        """Get size of heap. O(1)."""
        return len(self._hl)

    def __heapify(self, i):
        max = None
        
        for child in self.__children(i):
            if max == None or self._hl[max] < self._hl[child]:
                max = child
        
        if max == None:
            return

        if self._hl[i] < self._hl[max]:
            self._hl[i], self._hl[max] = self._hl[max], self._hl[i]
            self.__heapify(max)

    def __children(self, i):
        first_child = (self.__n * i) + 1

        if first_child >= self.size():
            return range(0, 0)
        
        last_child = (self.__n * i) + self.__n

        while last_child >= self.size():
            last_child -= 1
        
        return range(first_child, last_child + 1)

    def __parent(self, i):
        return (i - 1) // self.__n
