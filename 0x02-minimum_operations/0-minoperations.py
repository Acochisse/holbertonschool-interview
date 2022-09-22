#!/usr/bin/env python3
"""
Module: evaluates the minimum number of operations to reach n printed 'H's
operations: copy all, paste
"""


def minOperations(n):
    """returns the minimum number of operations to reach n printed 'H's"""
    if n < 2:
        return 0
    i = 2
    num_ops = 0
    while i <= n:
        if n % i == 0:
            n = n / i
            num_ops += i
        else:
            i += 1
    return num_ops
