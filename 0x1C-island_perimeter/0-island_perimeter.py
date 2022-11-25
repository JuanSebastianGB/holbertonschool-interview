#!/usr/bin/python3
"""
Defines function to calculate the perimeter of an island
represented by a list of list of ints
"""


def validate_edge_cases(grid):
    """ Implement basic edge cases validation"""
    if not isinstance(type(grid), list):
        return None
    for row in grid:
        if not isinstance(type(row), list):
            return None
        for column in row:
            if not isinstance(type(column), int):
                return None
            if column not in (0, 1):
                return None
    return True


def island_perimeter(grid):
    """
    Calculates the perimeter of an island represented by a list of list of ints
    returns:
        the perimeter of the island
    """
    if validate_edge_cases(grid):
        return None
    perimeter = 0
    for index_row, row_list in enumerate(grid):
        for index_column, column_value in enumerate(row_list):
            if column_value == 1:
                perimeter += is_edge(grid, index_row, index_column)
    return perimeter


def is_edge(grid, row, column):
    """
    Determines if the given cell is on the edge of the island

    parameters:
        grid [list of lists of ints]: represents the island
        row [int]: the index of row for the current cell
        column [int]: the index of column for the current cell

    returns:
        1-4, if the given cell is on an edge, the number of edges
        0, if the cell of land is in the interior of the island
    """
    edge_count = 0
    if row == 0:
        edge_count += 1
    if row == (len(grid) - 1):
        edge_count += 1
    if row != 0 and grid[row - 1][column] == 0:
        edge_count += 1
    if row != (len(grid) - 1) and grid[row + 1][column] == 0:
        edge_count += 1
    if column == 0:
        edge_count += 1
    if column == (len(grid[row]) - 1):
        edge_count += 1
    if column != 0 and grid[row][column - 1] == 0:
        edge_count += 1
    if column != (len(grid[row]) - 1) and grid[row][column + 1] == 0:
        edge_count += 1
    return edge_count
