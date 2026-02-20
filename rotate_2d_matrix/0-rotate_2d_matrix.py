#!/usr/bin/python3
"""Rotate a 2D matrix in-place by 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    """Rotate an n x n 2D matrix by 90 degrees clockwise in-place.

    The function transposes the matrix then reverses each row so the
    rotation is done without allocating another matrix.

    Args:
        matrix (list of list of int): 2D square matrix (n x n). Assumed
            non-empty and well-formed.
    """
    n = len(matrix)

    # Transpose (swap matrix[i][j] with matrix[j][i])
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row to complete the 90° clockwise rotation
    for row in matrix:
        row.reverse()
