#!/usr/bin/python3
"""determines if all the boxes can be opened."""


def checkBoxes(listOfKeys, boxes):
    """Checking all the keys"""
    totalBoxes = boxes.__len__()
    for index in range(totalBoxes):
        if index in boxes[index]:
            if listOfKeys.count(index) == 1:
                return False
    return True


def canUnlockAll(boxes):
    """Filling a list of keys"""
    if type(boxes) is not list or boxes.__len__() <= 0:
        return False
    listOfKeys = []
    for box in boxes:
        for index in box:
            listOfKeys.append(index)
    return checkBoxes(listOfKeys, boxes)
