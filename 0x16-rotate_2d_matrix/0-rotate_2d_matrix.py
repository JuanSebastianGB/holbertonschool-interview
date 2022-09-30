#!/usr/bin/env python3
"""
ROTATE_MATRIX
"""


def rotate_2d_matrix(matrix):
    """
    We're going to take the first element of each list, then the second
    element of each list, and so on, and put them in a new list.
    Then we're going to take the first element of the new list,
    and put it in the first list, then the second element of the new list, and
    put it in the second list, and so on.
    We're going to do this for each element in the new list.
    :param matrix: a list of lists, where each list is a list of integers
    """
    matrix_length = len(matrix)
    aux_list = []

    for selected_list in range(matrix_length):
        for list_element in range(matrix_length - 1, -1, -1):
            aux_list.append(matrix[list_element][selected_list])

    for selected_list in range(matrix_length):
        for list_element in range(matrix_length):
            matrix[selected_list][list_element] = aux_list.pop(0)
