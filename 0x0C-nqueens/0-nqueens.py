#!/usr/bin/python3
"""
Module to get nqueens
"""
import sys


def queens(solution: list, row: int, col: int, board_size: int) -> None:
    """
    prints solutions for nqueens challenge
    :solution: list of lists with the position of the queens in the board
    in such way that they don't attack each other
    :row: row position
    :col: column position
    :board_size: size of the chess board
    """
    while col < board_size:
        position = [row, col]
        if check_attack(solution, position):
            solution.append(position)
            if row == board_size - 1:
                print(solution)
                solution.pop()
            else:
                queens(solution, row + 1, 0, board_size)
        col += 1
    if len(solution) > 0:
        solution.pop()
    return


def check_attack(solution: list, pos: list) -> bool:
    """
    Check if the position is valid (rows, cols and diagonals not equal)
    :solution: list where are the positions to compare
    :pos: new position to evaluate
    return True if it is valid, False otherwise
    """
    for elem in solution:
        row = pos[0] == elem[0]
        col = pos[1] == elem[1]
        diagonal = abs(pos[0] - elem[0]) == abs(pos[1] - elem[1])
        if row or col or diagonal:
            return False
    return True


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
    queens([], 0, 0, N)
