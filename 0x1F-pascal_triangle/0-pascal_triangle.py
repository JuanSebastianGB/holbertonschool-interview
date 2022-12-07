#!/usr/bin/python3
""" Pascal pascalTriangle interview task"""


def pascal_triangle(n):
    """ Returns a list of lists of integers that are a representation
    of Pascal's pascalTriangle of size n
    """
    pascalTriangle = []
    if n <= 0:
        return pascalTriangle
    previous = [1]
    for rowNumber in range(n):
        listRow = []
        if rowNumber == 0:
            listRow = [1]
        else:
            for i in range(rowNumber + 1):
                if i == 0:
                    listRow.append(0 + previous[i])
                elif i == (rowNumber):
                    listRow.append(previous[i - 1] + 0)
                else:
                    listRow.append(previous[i - 1] + previous[i])
        previous = listRow
        pascalTriangle.append(listRow)
    return pascalTriangle
