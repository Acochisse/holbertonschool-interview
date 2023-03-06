#!/usr/bin/python3 
'''
module for evaluating the perimeter of an island
'''

def island_perimeter(grid):
    '''
    returns the perimeter of the island described in grid
    '''
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimeter += 4
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2
    return perimeter
