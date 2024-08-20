//
// Created by ziclaud on 07/08/24.
//

#ifndef BASIC_SOLVER_H
#define BASIC_SOLVER_H

#include <stdbool.h>

void remove_poss_pos(int s[9][9], int poss_pos[9][9][9], bool *is_changed);

void add_sudoku(int s[9][9], int poss_pos[9][9][9], int *solved_num);

void solve_basic(int s[9][9], int poss_pos[9][9][9], bool *is_changed, int *solved_num);

#endif //BASIC_SOLVER_H
