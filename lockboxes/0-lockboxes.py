#!/usr/bin/python3
"""Module to determine if all boxes can be opened."""


def canUnlockAll(boxes):
    """Determines if all boxes can be opened."""
    if not boxes:
        return True

    n = len(boxes)
    opened = set([0])
    stack = [0]

    while stack:
        current_box = stack.pop()

        for key in boxes[current_box]:
            if isinstance(key, int) and 0 <= key < n and key not in opened:
                opened.add(key)
                stack.append(key)

    return len(opened) == n
