#!/usr/bin/python3
"""module to get minimum operations
"""


def minOperations(n):
    """
    calculates the fewest number of operations needed
    to result in exactly n H characters in the file
    """
    if n == 0 or n == 1:
        return 0
    i = 2
    operations = []
    while i <= n:
        if n % i == 0:
            operations.append(i)
            n /= i
        else:
            i += 1
    return sum(operations)
