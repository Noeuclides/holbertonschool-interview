#!/usr/bin/python3
"""
Module
"""


def canUnlockAll(boxes):
    """determine if all the boxes can be opened
    """
    if boxes[0] is None:
        return False

    len_boxes = [i for i in range(len(boxes))]
    state = [0 for i in range(len(boxes))]
    box_keys = dict(zip(len_boxes, state))
    box_keys[0] = 1
    keys = [key for key in boxes[0]]
    k = 0
    while k in range(len(keys)):
        if keys[k] < len(boxes) and boxes[keys[k]]:
            for ki in boxes[keys[k]]:
                keys.append(ki)
            box_keys[keys[k]] = 1

        k = keys[k]
    box_keys[k] = 1
    for v in box_keys.values():
        if v == 0:
            return False
    return True
