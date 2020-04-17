#!/usr/bin/python3
"""
Module
"""


def canUnlockAll(boxes):
    """determine if all the boxes can be opened
    """
    keys = sorted(list(set(boxes[0])))
    keys_used = []
    count = 1

    if not keys:
        return False

    index = keys[0]

    a.remove(8)
    while index < len(boxes) or keys:
        keys.append(boxes[index])
        keys = sorted(list(set(boxes[index])))
        keys.remove(index)
        index = keys[0]
        count += 1

    if count == len(boxes):
        return True

    return False
    
