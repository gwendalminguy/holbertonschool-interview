#!/usr/bin/python3
"""
0-lockboxes.py
Module containing the method canUnlockAll.
"""

def canUnlockAll(boxes: list) -> bool:
    """
    Determine if all boxes can be open.
    Each box contains a list of zero or more integers, each representing a key (the index of the box it opens).
    First box is always unlocked.
    """
    openable = [False for _ in boxes]
    newly_found = 1
    found = 1
    keys = [0]

    for _ in boxes:                                             # For as many times as there are boxes.
        for key in keys[found - newly_found:]:                  # For each new key found.
            newly_found = 0                                     # Reset number of newly found keys.
            for new in boxes[key]:                              # For each new key found in the box newly opened box.
                if new not in keys and new <= len(boxes):       # Add each key only if not already in keys and if it opens an actual box.
                    keys.extend(boxes[key])
                    newly_found += 1
                    found += 1

    for key in keys:
        openable[key] = True

    return all(openable)
