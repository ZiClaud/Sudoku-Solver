//
// Created by ziclaud on 08/08/24.
//

#include "med_solver.h"
#include "../basics/basic_operations.h"
#include "../basics/basics.h"

/// Removes poss val if its the only one in the row
void _only_row(int s[9][9], int poss[9][9][9], const int row, const int col, bool *is_changed) {
    for (int c = 0; c < 9; ++c) {
        if (contains(poss[row][col], s[row][c])) {

        }
    }
}

/// Places all [possible_positions] numbers that are the only ones in the same row/col/square
void place_possible_positions_med(int s[9][9], int possible_positions[9][9][9], bool *is_changed) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (s[row][col] == 0) {
                _only_row(s, possible_positions, row, col, is_changed);
                //_only_col(s, possible_positions, row, col, is_changed);
                //_only_square(s, possible_positions, row, col, is_changed);
            } else {
                // Sets all values to VOID_CELL
                for (int i = 0; i < 9; ++i) {
                    possible_positions[row][col][i] = VOID_CELL;
                }
            }
        }
    }
}

void solve_med(int s[9][9], int possible_positions[9][9][9], bool *is_changed, int *solved_num) {
    place_possible_positions_med(s, possible_positions, is_changed);
    // TODO: add_sudoku(s, possible_positions, solved_num); ?
}
