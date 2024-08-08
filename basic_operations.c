#include <assert.h>
#include "basic_operations.h"
#include "basics.h"


// Returns true if list contains value
bool contains(int list[9], int val) {
    return list[val - 1] == val;
}


void _remove(int list[9], int val, bool *number_was_removed) {
    // TODO: assert(val >= 1 && val <= 9);
    if (val >= 1 && val <= 9) {
        *number_was_removed = true;
        list[val - 1] = VOID_CELL;
    }
}


int set_tot_need_solving(int s[9][9]) {
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
