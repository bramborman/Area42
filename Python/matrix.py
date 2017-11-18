class Matrix:
    def __init__(self, array):
        """ Vytvoreni matice """
        pass

    @staticmethod
    def zero_matrix(height, width):
        """ Staticka metoda na vytovreni nulove matice """
        pass

    @staticmethod
    def unit_matrix(side):
        """ Staticka metoda na vytvoreni jednotkove matice """
        pass

    def __str__(self):
        """ Pretizeni operatoru __str__ na prevod matice na string """
        pass

    def __setitem__(self, tup, new_value):
        """ Pretizeni setitemu na nastaveni prvku matice """
        pass

    def __getitem__(self, tup):
        """ Pretizeni getitemu na vypsani prvku matice """
        pass

    def get_num_cols(self):
        """ Vypsani poctu sloupcu matice """
        pass

    def get_num_rows(self):
        """ Vypsani poctu radku matice """
        pass

    def transposition(self):
        """ Vrati novou matici, ktera je transpozici puvodni matice """
        pass

    def is_square(self):
        """ Rozhodne, jestli je matice ctvercova """
        pass

    def is_symmetric(self):
        """ Rozodne, jestli je matice symetricka """
        pass

    def __eq__(self, other_matrix):
        """ Pretizeni operatoru ==; tzn jestli se dve matice rovnaji """
        pass

    def __ne__(self, other_matrix):
        """ Pretizeni operatoru !=; tzn jestli jsou dve matice rozdilne """
        pass

    def __add__(self, other_matrix):
        """ Pretizeni operatoru + na scitani matic """
        pass

    def __sub__(self, other_matrix):
        """ Pretizeni operatoru - na odecitani matic """
        pass

    def __mul__(self, other_matrix):
        """ Pretizeni operatoru * na nasobeni matic """
        pass

    def __rmul__(self, constant):
        """ Pretizeni operatoru * na nasobeni matice konstantou """
        pass
