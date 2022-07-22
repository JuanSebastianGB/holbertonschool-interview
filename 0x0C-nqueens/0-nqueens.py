#!/usr/bin/env python3

from typing import List
import sys


def get_size():
    """
    Get the size of the board.
    """
    arguments = sys.argv
    if len(arguments) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        n = int(arguments[1])
        if n < 4:
            print('N must be at least 4')
            sys.exit(1)
    except ValueError:
        print('N must be an integer')
        sys.exit(1)
    return n


def create_board(board_size: int) -> List[List[str]]:
    """
    Create a board.
    """
    board = [0 * board_size for _ in range(board_size)]
    print(board)


def solve_n_queens(n: int) -> List[List[str]]:
    """
    Solve the n-queens problem.

    Args:
        n: The size of the board.

    Returns:
        A list of solutions.
    """


if __name__ == '__main__':
    board_size = get_size()
    create_board(board_size)
