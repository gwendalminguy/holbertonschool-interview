#!/usr/bin/python3
"""
0-minoperations.py
Module containing the method minOperations.
"""

def minOperations(n):
    """
    Determine minimum operations to reach n.
    Only operations available are COPY ALL and PASTE.
    """
    h = 1
    copy = 1
    operations = 1

    if n <= 1:
        return 0

    while h != n:
        # Multiple found
        if h > 1 and n % h == 0:
            while h != n:
                # New multiple found
                if n % h == 0:
                    copy = h
                    operations += 1
                h += copy
                operations += 1

        if h == n:
            break

        h += 1
        operations += 1

    return operations
