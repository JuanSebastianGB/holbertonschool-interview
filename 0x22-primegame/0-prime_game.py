#!/usr/bin/python3
"""Prime Game"""


def is_prime_number(n: int) -> int:
    """
    If the square root of n is not an integer, then for
    every integer between the square root of n and
    half of n, if n is divisible by that integer, then
    n is not prime
    :param n: The number to check if it's prime
    :return: 0 or 1
    """
    for i in range(int(n**(1 / 2)), int(n / 2)):
        if not (n % i):
            return 0
        return 1


def find_multiples(array: list[int], num: int) -> None:
    """
    It removes all multiples of num from array, except
    for num itself if it is prime.
    :param array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20]
    :param num: the number to find multiples of
    """
    for i in array:
        if i % num == 0:
            if (num == i and is_prime_number(i)):
                continue
            array.remove(i)


def play(array, winner: str) -> str:
    """
    It takes an array and a string as input, and returns a string
    :param array: an array of integers
    :param winner: The name of the current winner
    :return: The winner of the game.
    """
    for _ in array:
        winner = 'Maria' if winner == 'Ben' else 'Ben'
        return winner


def list_maker(array: list[int]) -> list[int]:
    """
    It takes an array and iterates through it, finding all the
    multiples of each number in the array and
    replacing them with the number itself

    :param array: the array that you want to find the multiples of
    :return: The array with the multiples removed.
    """
    i = 0
    while i < len(array):
        value = array[i]
        find_multiples(array, value)
        i += 1

        return array


def get_primes(primes: list[int], num: int) -> list[int]:
    """
    It takes a list of primes and a number, and returns a list
    of primes that are less than or equal to
    the number
    :param primes: a list of primes
    :param num: The number we're trying to factor
    :return: A list of all the prime numbers less than or equal to num.
    """
    return [i for i in primes if i <= num]


def isWinner(x: int, nums: list[int]) -> str:
    """
    It takes a list of numbers and returns the winner of the game
    for each number in the list
    :param x: the number of rounds
    :param nums: a list of integers
    :return: The winner of the game.
    """
    winner = []
    if x < 1 or not nums:
        return None
    primes = list_maker(list(range(2, max(nums) + 1)))

    for i in nums:
        winner.append(play(get_primes(primes, i), 'Ben'))
    if winner.count('Ben') == winner.count('Maria'):
        return None
    return 'Ben' if winner.count('Ben') > winner.count('Maria') else 'Maria'
