#!/usr/bin/python3
"""
0-nqueens.py
Script finding a solution for the N Queens problem.
"""

import sys


def main():
    """
    Solves the N Queens problem.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []

    allowed = [[1 for cell in range(n)] for row in range(n)]

    backtrack([], n, allowed, solutions, 0)

    for solution in solutions:
        print(solution)

    # print(len(solutions))


def print_board(state: list[list], size: int) -> None:
    """
    Print the state of the board.
    """
    board = [[0 for cell in range(size)] for row in range(size)]

    for i, j in state:
        board[i][j] = 1

    for row in board:
        print(row)

    print("\n")


def invalidate(allowed: list[int], coordinates: list[int], size: int) -> list[list]:
    """
    Invalidate forbidden positions based on the coordinates of the new queen.
    """
    queen_i, queen_j = coordinates
    new_allowed = [[value for value in row] for row in allowed]

    # Invalidating row and column
    for n in range(size):
        new_allowed[queen_i][n] = 0
        new_allowed[n][queen_j] = 0

    check_i = queen_i
    check_j = queen_j

    # Find starting position for diagonal A
    while check_i > 0 and check_j > 0:
        check_i -= 1
        check_j -= 1
    
    # Invalidating diagonal A
    while check_i < size and check_j < size:
        new_allowed[check_i][check_j] = 0
        check_i += 1
        check_j += 1

    check_i = queen_i
    check_j = queen_j

    # Find starting position for diagonal B
    while check_i < size - 1 and check_j > 0:
        check_i += 1
        check_j -= 1

    # Invalidating diagonal B
    while check_i >= 0 and check_j < size:
        new_allowed[check_i][check_j] = 0
        check_i -= 1
        check_j += 1

    return new_allowed


def is_complete(state: list[list], size: int) -> bool:
    """
    Check if all queens are placed on the board.
    """
    if len(state) == size:
        return True

    return False


def backtrack(state: list[list], size: int, allowed: list[list], solutions: list[list], line: int) -> None:
    """
    Explore every potential solution recursively.
    Each recursion level explores every possible
    column placement for a given line.
    """
    # Check ending condition
    if is_complete(state, size):
        solutions.append([row for row in state])
        # print_board(state, size)
        return

    i = line

    # Loop through all possible column placement
    for j in range(size):
        if allowed[i][j]:
            state.append([i, j])

            # Create new list of allowed positions
            new_allowed = invalidate(allowed, [i, j], size)

            # Call backtrack to explore column placements for new state
            backtrack(state, size, new_allowed, solutions, line + 1)

            state.pop()


if __name__ == "__main__":
    main()
