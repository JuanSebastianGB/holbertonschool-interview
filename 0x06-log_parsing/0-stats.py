#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""


from asyncio.log import logger
from sys import stdin
statusList = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def printStoredStats():
    """Prints the saved log"""
    print("File size: {}".format(size))
    for status in sorted(statusList.keys()):
        if statusList[status]:
            print("{}: {}".format(status, statusList[status]))


if __name__ == "__main__":
    """Entry point of the script"""

    size = 0
    counter = 0
    try:
        for actualLine in stdin:
            try:
                items = actualLine.split()
                size += int(items[-1])
                if items[-2] in statusList:
                    statusList[items[-2]] += 1
            except Exception as e:
                pass
            if counter == 9:
                printStoredStats()
                counter = -1
            counter += 1
    except KeyboardInterrupt as interruption:
        printStoredStats()
        raise
    printStoredStats()
