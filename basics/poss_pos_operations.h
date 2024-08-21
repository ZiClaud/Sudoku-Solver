//
// Created by ziclaud on 21/08/24.
//

#ifndef POSS_POS_OPERATIONS_H
#define POSS_POS_OPERATIONS_H

#include <stdbool.h>

void clear_poss_pos(int poss_pos[9][9][9], int row, int col);

void fill_with_every_number(int poss_pos[9][9][9]);

void remove_row(int s[9][9], int poss_pos[9][9][9], int row, int col, bool *is_changed);

void remove_col(int s[9][9], int poss_pos[9][9][9], int row, int col, bool *is_changed);

void remove_square(int s[9][9], int poss_pos[9][9][9], int row, int col, bool *is_changed);

#endif //POSS_POS_OPERATIONS_H
