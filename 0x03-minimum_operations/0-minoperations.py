#!/usr/bin/python3
"""Task for define the min quantity of operations"""


def minOperations(n):
    """Calculates the minimun quantity of operations"""
    result = 0
    for i in range(2, n):
        while n % i == 0:
            result += i
            n = n/i
    return result
