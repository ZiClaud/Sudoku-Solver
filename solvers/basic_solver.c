#include "basic_solver.h"
#include "../basics/basic_operations.h"
#include "../basics/basics.h"

void _remove_row(int s[9][9], int poss[9][9][9], const int row, const int col, bool *is_changed) {
    for (int c = 0; c < 9; ++c) {
        if (contains(poss[row][col], s[row][c])) {
            rmv(poss[row][col], s[row][c], is_changed);
        }
    }
}

void _remove_col(int s[9][9], int poss[9][9][9], const int row, const int col, bool *is_changed) {
    for (int r = 0; r < 9; ++r) {
        if (contains(poss[row][col], s[r][col])) {
            rmv(poss[row][col], s[r][col], is_changed);
        }
    }
}

/// Removes all possible values in poss[row][col], that also appear in the row and col
void remove_row_and_col(int s[9][9], int poss[9][9][9], const int row, const int col, bool *is_changed) {
    _remove_row(s, poss, row, col, is_changed);
    _remove_col(s, poss, row, col, is_changed);
}

/// Removes all possible values in poss[row][col], that also appear in the square it's in
void remove_square(int s[9][9], int poss[9][9][9], const int row, const int col, bool *is_changed) {
    int t_row = row / 3;
    int t_col = col / 3;

    t_row *= 3;
    t_col *= 3;

    for (int r = t_row; r < t_row + 3; ++r) {
        for (int c = t_col; c < t_col + 3; ++c) {
            if (contains(poss[row][col], s[r][c])) {
                rmv(poss[row][col], s[r][c], is_changed);
            }
        }
    }
}

/// Removes all [possible_positions] numbers that are not in the same row/col/square
void remove_possible_positions_basic(int s[9][9], int possible_positions[9][9][9], bool *is_changed) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (s[row][col] == 0) {
                remove_row_and_col(s, possible_positions, row, col, is_changed);
                remove_square(s, possible_positions, row, col, is_changed);
            } else {
                // Sets all values to VOID_CELL
                for (int i = 0; i < 9; ++i) {
                    possible_positions[row][col][i] = VOID_CELL;
                }
            }
        }
    }
}

/// Add all sudoku's possible positions where theres just a single possible position in that cell
void add_sudoku(int s[9][9], int possible_positions[9][9][9], int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int count = 0;
            int val = VOID_CELL;
            for (int i = 0; i < 9; ++i) {
                if (possible_positions[row][col][i] != VOID_CELL) {
                    count++;
                    val = possible_positions[row][col][i];
                }
            }
            if (count == 1) {
                insert_value(s, row, col, val, solved_num);
            } else if (count == 0 && s[row][col] == 0) {
                s[row][col] = VOID_CELL;
            }
        }
    }
}

/// Basic rules - Removes Rows/Cols/Square
void solve_basic(int s[9][9], int possible_positions[9][9][9], bool *is_changed, int *solved_num) {
    remove_possible_positions_basic(s, possible_positions, is_changed);
    add_sudoku(s, possible_positions, solved_num);
}
