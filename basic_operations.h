//
// Created by ziclaud on 07/08/24.
//

#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <stdbool.h>

bool contains(int list[9], int val);

void _remove(int list[9], int val, bool *number_was_removed);

int set_solvable(int s[9][9]);

#endif //BASIC_OPERATIONS_H
