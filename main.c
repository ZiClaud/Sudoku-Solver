#include <stdbool.h>
#include <stdio.h>
#include "print.h"
#include "basic_operations.h"
#include "basic_solver.h"
#include "test.h"

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

    int sudoku[9][9];
    set_sudoku(sudoku);

    int possible_positions[9][9][9];

    const int solvable = set_solvable(sudoku);
    int solved = 0;


    fill_with_every_number(possible_positions);

    printf("Start:\n\n");
    print_sudoku(sudoku);

    do {
        number_was_removed = false;
        solve_easy(sudoku, possible_positions, &number_was_removed, &solved);
    } while (number_was_removed);

    print_sudoku(sudoku);
    printf("Solved %d/%d:\n\n", solved, solvable);

    return 0;
}
