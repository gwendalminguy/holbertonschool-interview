#!/usr/bin/python3
"""
0-rain.py
Module containing funcitons to determine the quantity of water retention.
"""
from typing import List


def rain(walls: List[int]) -> int:
    """
    Determine the quantity of water retention,
    by turning a list of integers into a matrix,
    and measuring the final quantity by iteration.
    """
    if type(walls) != list:
        raise ValueError("Walls must be a list.")

    for item in walls:
        if type(item) != int:
            raise ValueError("Walls must be a list of integers.")

    if not len(walls):
        return 0

    matrix = to_matrix(walls)
    # print_matrix(matrix)

    return measure_retention(matrix)


def to_matrix(walls: List[int]) -> List[List[bool]]:
    """
    Transform a list of integers into a two-dimensional matrix.
    """
    width = len(walls)
    height = max(walls)

    matrix = []

    for j in range(height):
        row = []

        for i in range(width):
            value = True if walls[i] >= height - j else False
            row.append(value)

        matrix.append(row)

    return matrix


def print_matrix(matrix: List[List[bool]]) -> None:
    """
    Print a visual representation of a matrix.
    """
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j]:
                print(" X ", end="")
            else:
                print(" . ", end="")

        print()


def measure_retention(matrix: List[List[bool]]) -> int:
    """
    Measure the water retention from a matrix.
    """
    total = 0

    for line in matrix:
        inside = False
        water = 0

        for cell in line:
            if cell:
                total += water
                water = 0
                inside = True
            elif inside:
                water += 1

    return total
