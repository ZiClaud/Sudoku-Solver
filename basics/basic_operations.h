//
// Created by ziclaud on 07/08/24.
//

#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <stdbool.h>

bool contains(int list[9], int val);

void rmv(int list[9], int val, bool *number_was_removed);

int set_to_solve(int s[9][9]);

void fill_with_every_number(int poss[9][9][9]);

#endif //BASIC_OPERATIONS_H
