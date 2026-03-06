#!/usr/bin/python3
"""Island perimeter calculation."""


def island_perimeter(grid):
    """Return the perimeter of the island described by *grid*.

    The grid is a rectangular list of lists containing 0 (water) or 1 (land).
    We compute the contribution of each land cell by checking its four
    neighbors; each side that is water or off the grid adds one to the
    perimeter.
    """

    if not grid or not grid[0]:
        return 0

    height = len(grid)
    width = len(grid[0])
    perimeter = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] != 1:
                continue
            # up
            if i == 0 or grid[i - 1][j] == 0:
                perimeter += 1
            # down
            if i == height - 1 or grid[i + 1][j] == 0:
                perimeter += 1
            # left
            if j == 0 or grid[i][j - 1] == 0:
                perimeter += 1
            # right
            if j == width - 1 or grid[i][j + 1] == 0:
                perimeter += 1
    return perimeter
