//
// Created by ziclaud on 21/08/24.
//

#include "poss_pos_operations.h"

#include "basics.h"
#include "basic_operations.h"

/// Sets all poss_pos values to VOID_CELL
void clear_poss_pos(int poss_pos[9][9][9], const int row, const int col) {
    // Sets all values to VOID_CELL
    for (int i = 0; i < 9; ++i) {
        poss_pos[row][col][i] = VOID_CELL;
    }
}


/// Fills poss_pos with all numbers (1 to 9)
void fill_with_every_number(int poss_pos[9][9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            for (int i = 0; i < 9; ++i) {
                poss_pos[row][col][i] = i + 1;
            }
        }
    }
}

/// Removes all [poss_pos] cols in a row (?)
void remove_row(int s[9][9], int poss_pos[9][9][9], const int row, const int col, bool *is_changed) {
    for (int c = 0; c < 9; ++c) {
        if (contains(poss_pos[row][col], s[row][c])) {
            rmv(poss_pos[row][col], s[row][c], is_changed);
        }
    }
}

/// Removes all [poss_pos] rows in a col (?)
void remove_col(int s[9][9], int poss_pos[9][9][9], const int row, const int col, bool *is_changed) {
    for (int r = 0; r < 9; ++r) {
        if (contains(poss_pos[row][col], s[r][col])) {
            rmv(poss_pos[row][col], s[r][col], is_changed);
        }
    }
}


/// Removes all possible values in poss_pos[row][col], that also appear in the square it's in
void remove_square(int s[9][9], int poss_pos[9][9][9], const int row, const int col, bool *is_changed) {
    int t_row = row / 3;
    int t_col = col / 3;

    t_row *= 3;
    t_col *= 3;

    for (int r = t_row; r < t_row + 3; ++r) {
        for (int c = t_col; c < t_col + 3; ++c) {
            if (contains(poss_pos[row][col], s[r][c])) {
                rmv(poss_pos[row][col], s[r][c], is_changed);
            }
        }
    }
}
