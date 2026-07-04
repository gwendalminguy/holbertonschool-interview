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
        # End of list reached
        if i >= len(data):
            return True

        # Keeping 8 least significant bits only
        byte = data[i] & 0b11111111

        # ASCII
        if byte & 0b10000000 == 0b00000000:
            i += 1
            continue

        # Multi Byte (Continuation Bytes: 1)
        elif byte & 0b11100000 == 0b11000000:
            if not check_continuation_bytes(data, i + 1, 1):
                return False
            i += 2

        # Multi Byte (Continuation Bytes: 2)
        elif byte & 0b11110000 == 0b11100000:
            if not check_continuation_bytes(data, i + 1, 2):
                return False
            i += 3

        # Multi Byte (Continuation Bytes: 3)
        if byte & 0b11111000 == 0b11110000:
            if not check_continuation_bytes(data, i + 1, 3):
                return False
            i += 4

        else:
            return False

        continue


def check_continuation_bytes(data: list[int], i: int, n: int) -> bool:
    """
    Checks for the right number of continuation bytes after
    a multi-byte codepoint, and their range.
    """
    for j in range(n):
        if i + j >= len(data):
            return False

        # Keeping 8 least significant bits only
        byte = data[i + j] & 0b11111111

        if byte & 0b11000000 != 0b11000000:
            return False

    return True
