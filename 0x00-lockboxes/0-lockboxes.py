#!/usr/bin/python3
"""a function that unlocks all boxes"""


def canUnlockAll(boxes):
    """a function that unlocks all boxes"""
    keys = [0]
    for key in keys:
        for key2 in boxes[key]:
            if key2 not in keys and key2 < len(boxes):
                keys.append(key2)
    if len(keys) == len(boxes):
        return True
    return False