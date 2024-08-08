#include "basic_solver.h"
#include "basic_operations.h"
#include "basics.h"

void _remove_row(int s[9][9], int poss[9][9][9], int row, int col, bool *number_was_removed) {
    for (int c = 0; c < 9; ++c) {
        if (contains(poss[row][col], s[row][c])) {
            //_remove(poss[row][col], s[row][c], number_was_removed);
        }
    }
}

void _remove_col(int s[9][9], int poss[9][9][9], int row, int col, bool *number_was_removed) {
    // TODO: Fix
    for (int r = 0; r < 9; ++r) {
        if (contains(poss[row][col], s[r][col])) {
            _remove(poss[row][col], s[r][col], number_was_removed);
        }
    }
}

void remove_row_and_col(int s[9][9], int poss[9][9][9], int row, int col, bool *number_was_removed) {
    _remove_row(s, poss, row, col, number_was_removed);
    _remove_col(s, poss, row, col, number_was_removed);
}

void remove_square(int s[9][9], int poss[9][9][9], int row, int col, bool *number_was_removed) {
    int t_row = row / 3;
    int t_col = col / 3;

    for (int r = t_row; r < t_row + 3; ++r) {
        for (int c = t_col; c < t_col + 3; ++c) {
            if (contains(poss[row][col], s[r][c])) {
                _remove(poss[row][col], s[r][c], number_was_removed);
            }
        }
    }
}

/// Basic rules - Removes Rows/Cols/Square
void solve_easy(int s[9][9], int possible_positions[9][9][9], bool *number_was_removed, int *solved_num) {
    // Checks rows and cols
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (s[row][col] == 0) {
                remove_row_and_col(s, possible_positions, row, col, number_was_removed);
                remove_square(s, possible_positions, row, col, number_was_removed);
            } else {
                // Sets all values to VOID_CELL
                for (int i = 0; i < 9; ++i) {
                    possible_positions[row][col][i] = VOID_CELL;
                }
            }
        }
    }

    // Add all possible positions where theres just a number that fits there
    int count;
    int val;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            count = 0;
            val = VOID_CELL;
            for (int i = 0; i < 9; ++i) {
                if (possible_positions[row][col][i] != VOID_CELL) {
                    count++;
                    val = possible_positions[row][col][i];
                }
            }
            if (count == 1) {
                s[row][col] = val;
                (*solved_num)++;
            } else if (count == 0 && s[row][col] == 0) {
                s[row][col] = VOID_CELL;
            }
        }
    }
}
