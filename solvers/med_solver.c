//
// Created by ziclaud on 08/08/24.
//

#include "med_solver.h"

#include <assert.h>

#include "basic_solver.h"
#include "../basics/basic_operations.h"

/// Inserts value in [s] if its the only one in the row of [poss_pos]
void _only_row(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int i = 1; i <= 9; ++i) {
            int count = 0;
            int col = -1;

            for (int c = 0; c < 9; ++c) {
                if (contains(poss_pos[row][c], i)) {
                    count++;
                    col = c;
                }
            }
            if (count == 1 && s[row][col] == 0) {
                assert(col != -1);
                insert_value(s, poss_pos, row, col, i, solved_num);
                *is_changed = true;
                remove_poss_pos(s, poss_pos, is_changed);
                return;
            }
        }
    }
}

/// Inserts value in [s] if its the only one in the col of [poss_pos]
void _only_col(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    for (int col = 0; col < 9; ++col) {
        for (int i = 0; i < 9; ++i) {
            int count = 0;
            int row;

            for (int r = 0; r < 9; ++r) {
                if (contains(poss_pos[r][col], i)) {
                    count++;
                    row = r;
                }
            }
            if (count == 1 && s[row][col] == 0) {
                insert_value(s, poss_pos, row, col, i, solved_num);
                *is_changed = true;
                remove_poss_pos(s, poss_pos, is_changed);
                return;
            }
        }
    }
}

/// Places all [poss_pos] numbers that are the only ones in the same row/col/square
void place_poss_pos_med(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // TODO: FIX
            if (!*is_changed)
                _only_row(s, poss_pos, is_changed, solved_num);
            if (!*is_changed)
                _only_col(s, poss_pos, is_changed, solved_num);
            // if (!*is_changed)
            //    _only_square(s, poss_pos, is_changed, solved_num);
        }
    }
}

void solve_med(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    // TODO: Fix
    place_poss_pos_med(s, poss_pos, is_changed, solved_num);
}
