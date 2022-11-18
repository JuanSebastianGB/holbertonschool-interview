#!/usr/bin/python3
"""
Island perimeter interview task
"""


def island_perimeter(grid):
    """
    Island perimeter interview task
    """
    result = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i - 1 < 0 or grid[i - 1][j] == 0:
                    result += 1
                if grid[i + 1][j] or i + 1 >= len(grid) == 0:
                    result += 1
                if j - 1 < 0 or grid[i][j - 1] == 0:
                    result += 1
                if grid[i][j + 1] == 0 or j + 1 >= len(grid[i]):
                    result += 1
    return result
