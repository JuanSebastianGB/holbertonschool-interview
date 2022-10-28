#!/usr/bin/python3
"""
Fewest change Algorithm
"""
START_DATA = 0


def makeChange(coins, total):
    """ With a pile of coins of different values,
    return fewest number of coins needed to get a total amount.
    """
    if total < 1:
        return 0
    coins.sort()
    coins.reverse()
    fewest = START_DATA
    for coin in coins:
        if total <= 0:
            break
        buff = total // coin
        fewest += buff
        total -= (buff * coin)
    if total != 0:
        return -1
    return fewest
