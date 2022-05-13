#!/usr/bin/python3
"""Task for define the min quantity of operations"""


def minOperations(n=0):
    """Calculates the minimun quantity of operations"""

    if type(n) != int or n <= 0:
        return 0
    result, control = 0, 2

    while n > 1:
        if n % control != 0:
            control += 1
        else:
            n /= control
            result += control
    return result
