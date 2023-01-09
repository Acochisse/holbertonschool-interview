#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.
"""

def rain(walls):
    """finds the lowest wall relative to the index of the water and returns that as the water level"""
    if len(walls) <= 1:
        return 0
    
    water = 0
    for i in range(len(walls)):
        if walls[i] != max(walls):
            left = 0
            right = 0
            for j in range(0, i):
                if left < walls[j]:
                    left = walls[j]
            for k in range(i, len(walls)):
                if right < walls[k]:
                    right = walls[k]
            if left != 0 and right != 0:
                if left < right and left > walls[i]:
                    water += left - walls[i]
                elif right <= left and right > walls[i]:
                    water += right - walls[i]
    return water