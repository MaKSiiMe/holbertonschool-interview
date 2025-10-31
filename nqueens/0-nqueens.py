#!/usr/bin/python3
"""
N Queens Problem Solver
"""
import sys


def is_safe(board, row, col, n):
    """
    Check if it's safe to place a queen at board[row][col]
    """
    # Check if there's a queen in the same column
    for i in range(row):
        if board[i] == col:
            return False
        
        # Check diagonals
        if abs(board[i] - col) == abs(i - row):
            return False
    
    return True


def solve_nqueens(n, row, board, solutions):
    """
    Solve N Queens problem using backtracking
    """
    if row == n:
        # Found a solution
        solution = [[i, board[i]] for i in range(n)]
        solutions.append(solution)
        return
    
    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col
            solve_nqueens(n, row + 1, board, solutions)
            board[row] = -1  # Backtrack


def main():
    """
    Main function to handle input and print solutions
    """
    # Check number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    
    # Validate N is an integer
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    
    # Check N is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    
    # Solve N Queens
    board = [-1] * n
    solutions = []
    solve_nqueens(n, 0, board, solutions)
    
    # Print all solutions
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
