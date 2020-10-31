class Matrix:
    """
    Simple class representing a mathematical matrix
    """

    def __init__(self, cells):
        for row in cells:
            if len(row) != len(cells[0]):
                raise ValueError("Each row of a matrix must " +
                                 "be of the same length.")

        self.__cells = cells

    @staticmethod
    def zero_matrix(height, width):
        """
        Returns a zero matrix of the specified size

        Keyword arguments:
        height -- the height of the new matrix
        width -- the width of the new matrix
        """

        if height < 0 or width < 0:
            raise ValueError("Size must be greater than or equal to 0.")

        return Matrix([[0] * width for i in range(height)])

    @staticmethod
    def unit_matrix(size):
        """
        Returns a unit matrix of the specified size

        Keyword arguments:
        size -- the size of the new matrix (height and width)
        """

        if size < 0:
            raise ValueError("Size must be greater than or equal to 0.")

        return Matrix([[1 if i == j else 0 for j in range(size)]
                      for i in range(size)])

    def __str__(self):
        # Comprehensions are really fast - way faster than
        # appending string to string over and over again
        return "\n".join(" ".join(str(cell) for cell in row)
                         for row in self.__cells)

    def __validate_index_parameter(self, index):
        if len(index) != 2:
            raise ValueError("Invalid number of items in parameter index.")

        if (index[0] < 0 or index[0] >= self.get_num_rows() or
           index[1] < 0 or index[1] >= self.get_num_cols()):
            raise ValueError("Value(s) out of range in parameter index.")

    def __getitem__(self, index):
        self.__validate_index_parameter(index)
        return self.__cells[index[0]][index[1]]

    def __setitem__(self, index, value):
        self.__validate_index_parameter(index)
        self.__cells[index[0]][index[1]] = value

    def get_num_rows(self):
        """
        Gets the number of rows of the matrix
        """
        return len(self.__cells)

    def get_num_cols(self):
        """
        Gets the number of columns of the matrix
        """
        return len(self.__cells[0])

    def transpose(self):
        """
        Returns a new matrix that's a transposion to the current one
        """
        return Matrix([[self[j, i] for j in range(self.get_num_rows())]
                      for i in range(self.get_num_cols())])

    def is_square(self):
        """
        Gets a boolean value specificating
        whether the matrix is a square matrix
        """
        return self.get_num_rows() == self.get_num_cols()

    def is_symmetric(self):
        """
        Gets a boolean value specificating whether the matrix is symmetric
        """
        # If it's not square it's faster not to transpose
        # this matrix and return immediately
        return self.is_square() and self == self.transpose()

    def __eq__(self, other_matrix):
        if (self.get_num_rows() != other_matrix.get_num_rows()
           or self.get_num_cols() != other_matrix.get_num_cols()):
            return False

        for i in range(self.get_num_rows()):
            for j in range(self.get_num_cols()):
                if self[i, j] != other_matrix[i, j]:
                    return False

        return True

    def __ne__(self, other_matrix):
        return not self == other_matrix

    def __validate_same_size(self, other_matrix):
        if (self.get_num_rows() != other_matrix.get_num_rows()
           or self.get_num_cols() != other_matrix.get_num_cols()):
            raise ValueError("Both matrixes must be of the same size.")

    def __add__(self, other_matrix):
        self.__validate_same_size(other_matrix)
        return Matrix([[self[i, j] + other_matrix[i, j]
                      for j in range(self.get_num_cols())]
                      for i in range(self.get_num_rows())])

    def __sub__(self, other_matrix):
        self.__validate_same_size(other_matrix)
        return Matrix([[self[i, j] - other_matrix[i, j]
                      for j in range(self.get_num_cols())]
                      for i in range(self.get_num_rows())])

    def __mul__(self, other_matrix):
        if self.get_num_cols() != other_matrix.get_num_rows():
            raise ValueError("Number of columns in the first matrix " +
                             "and number of rows in the second matrix " +
                             "must be the same.")

        cells = []
        for i in range(self.get_num_rows()):
            cells.append([])

            for j in range(other_matrix.get_num_cols()):
                cells[i].append(0)

                for k in range(self.get_num_cols()):
                    cells[i][j] += self[i, k] * other_matrix[k, j]

        return Matrix(cells)

    def __rmul__(self, constant):
        return Matrix([[self[i, j] * constant
                      for j in range(self.get_num_cols())]
                      for i in range(self.get_num_rows())])
