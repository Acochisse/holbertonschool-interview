#!/usr/bin/python3
"""
Module file for makeChange
"""
import sys


def makeChange(coins, total):
    """
    Function that determines the fewest number of coins needed to meet a given
    amount total
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if total == 0:
            return count
        if coin <= total:
            count += total // coin
            total = total % coin

    if total != 0:
        return -1
    return count