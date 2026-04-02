#!/usr/bin/python3
"""
0-lockboxes.py
Module containing the method canUnlockAll.
"""


def canUnlockAll(boxes: list) -> bool:
    """
    Determine if all boxes can be open.
    Each box contains a list of zero or more integers,
    each representing a key (the index of the box it opens).
    First box is always unlocked.
    """
    openable = [False for _ in boxes]
    newly_found = 1
    found = 1
    keys = [0]

    for _ in boxes:
        for key in keys[found - newly_found:]:
            for new in boxes[key]:
                if new not in keys and new < len(boxes):
                    keys.append(new)
                    newly_found += 1
                    found += 1
            newly_found -= 1
            # print(keys)

    for key in keys:
        openable[key] = True

    return all(openable)
