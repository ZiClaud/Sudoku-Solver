//
// Created by ziclaud on 07/08/24.
//

#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <stdbool.h>

void clear_poss_pos(int poss_pos[9][9][9], int row, int col);

void insert_value(int s[9][9], int poss_pos[9][9][9], int row, int col, int val, int *solved_num);

bool contains(int list[9], int val);

bool has_errors(int s[9][9]);

void rmv(int list[9], int val, bool *is_changed);

int set_to_solve(int s[9][9]);

void fill_with_every_number(int poss_pos[9][9][9]);

#endif //BASIC_OPERATIONS_H
