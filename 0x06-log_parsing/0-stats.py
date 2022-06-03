#!/usr/bin/python3
'''reads stdin line by line and computes metrics'''


def main():
    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    regex = {
        "date": r"(20\d{2}-[01]?\d-(?:3[01]|[0-2]\d))",
        "time": "([0-5]\d:[0-5]\d:[0-5]\d\.\d+)",
        "ip":
            r"((?:(?:25[0-5]|2[0-4]\d|1?\d?\d)\.){3}"
            "(?:25[0-5]|2[0-4]\d|1?\d?\d)|\w+)",
        "code": "(\w+)",
        "size": "(\d+)",
        "path": "/projects/260"
    }
    pattern = \
        '^{ip} ?- ?\[{date} {time}\] "GET {path} HTTP/1.1" {code} {size}$'
    pattern = pattern.format(**regex)

    lineCounter = 0
    codeCounter = {}
    sizes = 0
    signal(SIGINT, passCaseNone)
    for actualLine in stdin:
        out = match(pattern, actualLine)
        if out:
            lineCounter += 1
            sizes += int(out.group(5))
            code = out.group(4)
            if code in list(map(str, valid_codes)):
                if code in codeCounter.keys():
                    codeCounter[code] += 1
                else:
                    codeCounter[code] = 1
            if lineCounter % 10 == 0:
                printLine(codeCounter, sizes)
    if lineCounter == 0 or lineCounter % 10 != 0:
        printLine(codeCounter, sizes)


def printLine(data, size):
    codes = list(data.keys())
    codes.sort()
    print("File size: {}".format(size))
    for code in codes:
        print(f"{code}: {data[code]}")


def passCaseNone():
    pass


if __name__ == "__main__":
    from re import match
    from sys import stdin
    from signal import signal
    from signal import SIGINT
    main()
