#!/usr/bin/env python3

"""
Prototype: def rotate_2d_matrix(matrix):
Do not return anything. The matrix must be edited in-place.
You can assume the matrix will have 2 dimensions and will not be empty.  
"""

def rotate_2d_matrix(matrix):
    """
    Rotate 2D Matrix
    """
    matrix.reverse()
    for i in range(len(matrix)):
        for j in range(i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            