#include <stdbool.h>
#include <stdio.h>

#include "print.h"
#include "basic_operations.h"
#include "basic_solver.h"

int possible_positions[9][9][9];

int sudoku[9][9] = {
    {0, 1, 0, 7, 9, 0, 3, 0, 0},
    {4, 0, 0, 0, 6, 0, 0, 1, 0},
    {0, 0, 9, 3, 8, 0, 0, 0, 5},
    {0, 5, 0, 6, 0, 3, 0, 0, 0},
    {0, 0, 0, 0, 7, 0, 6, 3, 2},
    {0, 6, 8, 0, 0, 9, 5, 0, 4},
    {2, 3, 0, 9, 0, 0, 4, 0, 0},
    {0, 0, 6, 8, 0, 2, 0, 0, 7},
    {9, 0, 1, 0, 0, 0, 0, 6, 0}
};

int sudoku2[9][9] = {
    {1, 2, 3, 4, 0, 0, 7, 8, 9},
    {2, 3, 4, 5, 6, 7, 8, 9, 1},
    {3, 4, 5, 6, 7, 8, 9, 1, 2},
    {4, 5, 6, 7, 8, 9, 1, 2, 3},
    {5, 6, 7, 8, 9, 1, 2, 3, 4},
    {6, 7, 8, 9, 1, 2, 3, 4, 5},
    {7, 8, 9, 1, 2, 3, 4, 5, 6},
    {8, 9, 1, 2, 3, 4, 5, 6, 7},
    {9, 1, 2, 3, 4, 5, 6, 7, 8}
};

void fill_with_zeros(int s[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = 0;
        }
    }
}

void fill_with_every_number(int s[9][9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            for (int i = 0; i < 9; ++i) {
                s[row][col][i] = i + 1;
            }
        }
    }
}

int main(void) {
    // Will be true if possible_positions changes a single number
    bool number_was_removed;

    int tot_need_solving = set_tot_need_solving(sudoku);
    int solved_num = 0;


    fill_with_every_number(possible_positions);

    printf("Start:\n\n");
    print_sudoku(sudoku);

    do {
        number_was_removed = false;
        solve_easy(sudoku, possible_positions, &number_was_removed, &solved_num);
    } while (number_was_removed);

    printf("Solved %d/%d:\n\n", solved_num, tot_need_solving);
    print_sudoku(sudoku);

    return 0;
}
