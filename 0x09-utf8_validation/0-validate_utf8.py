#!/usr/bin/python3
""" -*- coding: utf-8 -*-"""


def get_binary_representation(number):
    """
    It takes a number and returns a string of its binary representation
    :param number: The number to be converted to binary
    :return: The binary representation of the number.
    """
    return format(number, '#010b')[-8:]


def get_number_of_ones_at_start(binary_number: str, counter: int = 0):
    """
    It takes a binary number as a string and returns the number of ones
    at the start of the string
    :param binary_number: the binary number we're checking
    :param counter: This is the number of ones we've counted so far, defaults
    to 0 (optional)
    """

    for character in binary_number:
        if character == '0':
            break
        counter += 1
    return counter


def validUTF8(data: list) -> bool:
    """
    We count the number of bytes in the sequence that must be processed.
    If this number is different than zero at the end of the iteration,
    then the sequence is invalid

    :param data: The list of integers that we are going to process
    :type data: list
    :return: a boolean value.
    """

    number_of_bytes = 0
    for num in data:
        binary_representation = get_binary_representation(num)
        # Processing a new UTF-8 character.
        if number_of_bytes == 0:
            number_of_bytes = get_number_of_ones_at_start(
                binary_representation, number_of_bytes
            )
            if number_of_bytes == 0:
                continue
            if number_of_bytes == 1 or number_of_bytes > 4:
                return False
        else:
            # pattern `10xxxxxx`.
            if not (
                binary_representation[1] == '0' and
                    binary_representation[0] == '1'
            ):
                return False
        number_of_bytes -= 1
    return number_of_bytes == 0
