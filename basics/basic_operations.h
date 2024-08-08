//
// Created by ziclaud on 07/08/24.
//

#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <stdbool.h>

void clear_possible_positions(int possible_positions[9][9][9], int row, int col);

void insert_value(int s[9][9], int possible_positions[9][9][9], int row, int col, int val, int *solved_num);

bool contains(int list[9], int val);

void rmv(int list[9], int val, bool *is_changed);

int set_to_solve(int s[9][9]);

void fill_with_every_number(int poss[9][9][9]);

#endif //BASIC_OPERATIONS_H
