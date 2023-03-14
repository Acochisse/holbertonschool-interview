#!/usr/bin/python3
"""Prime Game"""

def isWinner(x, nums):
    """determines the winner of the game"""
    if not nums or x < 1:
        return None
    
    n = max(nums)
    primes = [True for i in range(n + 1)]
    primes[0] = False
    primes[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False
    
    count = 0

    for i in range(len(nums)):
        if primes[nums[i]]:
            count += 1
            
    if count % 2 == 0:
        return "Maria"
    return "Ben"
