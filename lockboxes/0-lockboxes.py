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
    keys = [0]
    found = 1

    for _ in boxes:                                             # For as many times as there are boxes.
        for key in keys[found - 1:]:                            # For each new key found.
            for new in boxes[key]:                              # For each new key found in the box newly opened box.
                if new not in keys and new <= len(boxes):       # Add each key only if not already in keys and if it opens an actual box.
                    keys.extend(boxes[key])
                    found += 1

    for key in keys:
        openable[key] = True

    return all(openable)
