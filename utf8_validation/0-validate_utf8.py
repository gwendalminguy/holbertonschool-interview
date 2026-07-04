#!/usr/bin/python3
"""
0-validate_utf8.py
Module containing the method validUTF8.
"""


BYTE_TYPE = {
    "240": 4,
    "224": 3,
    "192": 2
}

def validUTF8(data: list[int]) -> bool:
    """
    Checks if a sequence of bytes is a valid UTF-8 encoding.
    """
    i = 0

    while True:
        if i >= len(data):
            return True

        if data[i] >= 256:
            return False

        elif data[i] >= 240:
            if not check_continuation_bytes(data, i + 1, 3):
                return False
            i += 4

        elif data[i] >= 224:
            if not check_continuation_bytes(data, i + 1, 2):
                return False
            i += 3

        elif data[i] >= 192:
            if not check_continuation_bytes(data, i + 1, 1):
                return False
            i += 2

        else:
            i += 1

        continue


def check_continuation_bytes(data: list[int], i: int, n: int) -> bool:
    """
    Checks for the right number of continuation bytes after
    a multi-byte codepoint, and their range.
    """
    for j in range(n):
        if i + j >= len(data):
            return False
        if data[i + j] < 128 or data[i + j] >= 192:
            return False

    return True
