//
// Created by ziclaud on 08/08/24.
//

#include "med_solver.h"
#include "../basics/basic_operations.h"
#include "../basics/basics.h"

/// Removes poss val if its the only one in the row
void _only_row(int s[9][9], int poss[9][9][9], bool *is_changed, int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int i = 1; i <= 9; ++i) {
            int count = 0;
            int col;

            for (int c = 0; c < 9; ++c) {
                if (contains(poss[row][c], i)) {
                    count++;
                    col = c;
                }
            }
            if (count == 1 && s[row][col] == 0) {
                insert_value(s, poss, row, col, i, solved_num);
                *is_changed = true;
            }
        }
    }
}

/// Removes poss val if its the only one in the col
void _only_col(int s[9][9], int poss[9][9][9], bool *is_changed, int *solved_num) {
    for (int col = 0; col < 9; ++col) {
        for (int i = 0; i < 9; ++i) {
            int count = 0;
            int row;

            for (int r = 0; r < 9; ++r) {
                if (contains(poss[r][col], i)) {
                    count++;
                    row = r;
                }
            }
            if (count == 1 && s[row][col] == 0) {
                insert_value(s, poss, row, col, i, solved_num);
                *is_changed = true;
            }
        }
    }
}

/// Places all [possible_positions] numbers that are the only ones in the same row/col/square
void place_possible_positions_med(int s[9][9], int possible_positions[9][9][9], bool *is_changed, int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // TODO: FIX
            _only_row(s, possible_positions, is_changed, solved_num);
            // _only_col(s, possible_positions, is_changed, solved_num);
            // _only_square(s, possible_positions, is_changed, solved_num);
        }
    }
}

void solve_med(int s[9][9], int possible_positions[9][9][9], bool *is_changed, int *solved_num) {
    place_possible_positions_med(s, possible_positions, is_changed, solved_num);
}
