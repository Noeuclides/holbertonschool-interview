#!/usr/bin/python3
"""
rain module
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls
    of width 1, calculate how much water will be retained
    after it rains.
    - walls: list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    If the list is empty return 0.
    """
    rainwater = 0
    for i in range(1, len(walls) - 1):
        w = walls[i]
        left = max(max([walls[j] for j in range(i)]), w)
        right = max(max([walls[j] for j in range(i + 1, len(walls))]), w)
        rainwater += min(left, right) - w

    return rainwater
