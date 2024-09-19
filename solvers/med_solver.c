//
// Created by ziclaud on 08/08/24.
//

#include "med_solver.h"

#include <assert.h>
#include <stdio.h>

#include "basic_solver.h"
#include "../basics/basics.h"
#include "../basics/basic_operations.h"
#include "../basics/poss_pos_operations.h"

/// Inserts value in [s] if it's the only one in the row of [poss_pos]
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
                remove_row(s, poss_pos, row, col, is_changed);
                return;
            }
        }
    }
}

/// Inserts value in [s] if it's the only one in the col of [poss_pos]
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
                remove_col(s, poss_pos, row, col, is_changed);
                return;
            }
        }
    }
}

/// Returns the number of the vals inside the box (>= 1)
int _val_inside_box(int poss_pos[9][9][9], const int row, const int col, const int val) {
    int ris = 0;
    int t_row = row / 3;
    int t_col = col / 3;

    t_row *= 3;
    t_col *= 3;

    for (int r = t_row; r < t_row + 3; ++r) {
        for (int c = t_col; c < t_col + 3; ++c) {
            if (contains(poss_pos[r][c], val)) {
                ris++;
            }
        }
    }

    assert(ris != 0);
    return ris;
}

/// Inserts value in [s] if it's the only one in the box of [poss_pos]
void _check_box(int s[9][9], int poss_pos[9][9][9], const int row, const int col, bool *is_changed, int *solved_num) {
    for (int i = 0; i < 9; ++i) {
        const int val = poss_pos[row][col][i];
        if (val != VOID_CELL) {
            if (_val_inside_box(poss_pos, row, col, val) == 1) {
                insert_value(s, poss_pos, row, col, val, solved_num);
                *is_changed = true;
                remove_box(s, poss_pos, row, col, is_changed);
                return;
            }
        }
    }
}

/// Checks if every single value inside the box does appear only once
void _only_box(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (s[row][col] == 0) {
                _check_box(s, poss_pos, row, col, is_changed, solved_num);
                if (*is_changed) {
                    return;
                }
            }
        }
    }
}

/// Places all [poss_pos] numbers that are the only ones in the same row/col/box
void place_poss_pos_med(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (!*is_changed)
                _only_row(s, poss_pos, is_changed, solved_num);
            if (!*is_changed)
                _only_col(s, poss_pos, is_changed, solved_num);
            if (!*is_changed)
                _only_box(s, poss_pos, is_changed, solved_num);
        }
    }
}

void solve_med(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num) {
    // TODO: Test more
    place_poss_pos_med(s, poss_pos, is_changed, solved_num);
}
