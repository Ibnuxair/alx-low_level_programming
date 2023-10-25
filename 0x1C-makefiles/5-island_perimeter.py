#!/usr/bin/python3

""" This module a function def island_perimeter(grid). """


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid. """

    perimeter = 0

    # Define directions for movement (up, down, left, right)
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                # For each land cell, check its neighbors
                for dr, dc in directions:
                    r, c = row + dr, col + dc
                    if r < 0 or r >= len(grid) or c < 0 or  \
                       c >= len(grid[0]) or grid[r][c] == 0:
                        # If the neighbor is out of bounds or is water:
                        perimeter += 1

    return perimeter
