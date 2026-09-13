#!/usr/bin/python3
"""
0-rain.py
Module containing funcitons to determine the quantity of water retention.
"""


def rain(walls: list[int]) -> int:
    """
    Determine the quantity of water retention,
    by turning a list of integers into a matrix,
    and measuring the final quantity by iteration.
    """
    if not isinstance(walls, list):
        raise ValueError("Walls must be a list.")

    for value in walls:
        if not isinstance(value, int):
            raise ValueError("Walls must be a list of integers.")

    if not len(walls):
        return 0

    total = 0
    height = max(walls)

    for level in range(height):
        count = 0
        inside = False

        for value in walls:
            if height - level <= value:
                total += count
                count = 0
                inside = True
            elif inside:
                count += 1

    return total
