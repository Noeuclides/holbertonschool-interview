#!/usr/bin/python3
"""
Module
"""


def canUnlockAll(boxes):
    """determine if all the boxes can be opened
    """
    keys = sorted(list(set(boxes[0])))
    keys_used = [0]
    count = 1

    if not keys:
        return False
    if 0 in keys:
        keys.remove(0)

    index = keys[0]

    while index < len(boxes) - 1 and keys:
        keys.extend(boxes[index])
        keys = sorted(list(set(keys)))
        keys.remove(index)
        keys_used.append(index)
        for k in keys_used:
            if k in keys:
                keys.remove(k)
        if keys:
            index = keys[0]
        count += 1

    if count == len(boxes) - 1:
        return True

    return False
