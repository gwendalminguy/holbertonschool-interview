#!/usr/bin/python3
"""
0-stats.py
Script monitoring server activity.
"""

import re
import sys


def main():
    """
    Log statistics every ten calls on a server.
    Compute total size transfered and count of eache status code.
    """
    pattern = re.compile(
        r"^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - "
        r"\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d+\] "
        r"\"GET /projects/260 HTTP/1.1\" \d{3} \d+$"
    )

    statuses = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }

    i = 0
    total_size = 0

    try:
        for line in sys.stdin:
            # Validating format
            if not pattern.match(line):
                pass

            # Splitting and analyzing data
            data = line.split(" ")

            status_code = data[-2]
            statuses[status_code] += 1

            file_size = int(data[-1])
            total_size += file_size

            # Printing statistics
            if (i + 1) % 10 == 0:
                log(total_size, statuses)

            i += 1
    except KeyboardInterrupt:
        log(total_size, statuses)
    else:
        if (i + 1) % 10 == 0:
            log(total_size, statuses)


def log(total_size, statuses):
    """
    Helper function to log statistics.
    """
    print(f"File size: {total_size}")

    for code, value in statuses.items():
        if value:
            print(f"{code}: {value}")


if __name__ == "__main__":
    main()
