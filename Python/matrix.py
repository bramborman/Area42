class Matrix:
    def __init__(self, cells):
        if len(cells) < 1:
            raise ValueError("Matrix must have at least one row.")

        if len(cells[0]) < 1:
            raise ValueError("Matrix must have at least one column.")

        for row in cells:
            if len(row) != len(cells[0]):
                raise ValueError("Each row of a matrix must be of the same length.")

        self.__cells = cells

    @staticmethod
    def zero_matrix(height, width):
        return Matrix([[0] * width for i in range(height)])

    @staticmethod
    def unit_matrix(size):
        return Matrix([[1 if i == j else 0 for j in range(size)] for i in range(size)])

    def __str__(self):
        return "\n".join(" ".join(str(cell) for cell in row) for row in self.__cells)

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
        return len(self.__cells)

    def get_num_cols(self):
        return len(self.__cells[0])

    def transposition(self):
        return Matrix([[self[j, i] for j in range(self.get_num_rows())] for i in range(self.get_num_cols())])

    def is_square(self):
        return self.get_num_rows() == self.get_num_cols()

    def is_symmetric(self):
        # If it's not square it's faster not to transpose this matrix and return immediately
        return self.is_square() and self == self.transposition()

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
            raise ValueError("Both matrixes mus be of the same size.")

    def __add__(self, other_matrix):
        self.__validate_same_size(other_matrix)
        return Matrix([[self[i, j] + other_matrix[i, j] for j in range(self.get_num_cols())] for i in range(self.get_num_rows())])

    def __sub__(self, other_matrix):
        self.__validate_same_size(other_matrix)
        return Matrix([[self[i, j] - other_matrix[i, j] for j in range(self.get_num_cols())] for i in range(self.get_num_rows())])

    def __mul__(self, other_matrix):
        if self.get_num_cols() != other_matrix.get_num_rows():
            raise ValueError("Number of columns in the first matrix and number of rows in the second matrix must be the same.")

        cells = []
        for i in range(self.get_num_rows()):
            cells.append([])

            for j in range(other_matrix.get_num_cols()):
                cells[i].append(0)

                for k in range(self.get_num_cols()):
                    cells[i][j] += self[i, k] * other_matrix[k, j]

        return Matrix(cells)

    def __rmul__(self, constant):
        return Matrix([[self[i, j] * constant for j in range(self.get_num_cols())] for i in range(self.get_num_rows())])

print(Matrix([[1, 2, 3], [4, 5, 6]]) * Matrix([[-1, 3, -3, 1], [2, 0, 0, 5], [1, 5, 7, -10]]))