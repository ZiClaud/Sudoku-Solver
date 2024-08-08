#include <assert.h>
#include "basic_operations.h"
#include "basics.h"

/// Inserts value to sudoku
void insert_value(int s[9][9], int row, int col, int val, int *solved_num) {
    assert(s[row][col] == 0);
    s[row][col] = val;
    (*solved_num)++;
}

/// Returns true if list contains value (That's neither -1 nor 0)
bool contains(int list[9], const int val) {
    if (val == VOID_CELL || val == 0) {
        return false;
    }
    return list[val - 1] == val;
}

/// Removes all values of the list that can only contain numbers between 1 and 9
void rmv(int list[9], const int val, bool *is_changed) {
    assert(val >= 1 && val <= 9);
    *is_changed = true;
    list[val - 1] = VOID_CELL;
}

/// Sets value [to_solve]
int set_to_solve(int s[9][9]) {
    int tot_need_solving = 0;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (!s[row][col]) {
                tot_need_solving++;
            }
        }
    }
    return tot_need_solving;
}

/// Fills possible_positions with all numbers (1 to 9)
void fill_with_every_number(int poss[9][9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            for (int i = 0; i < 9; ++i) {
                poss[row][col][i] = i + 1;
            }
        }
    }
}