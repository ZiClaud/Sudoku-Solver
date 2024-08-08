#include <stdbool.h>
#include <stdio.h>
#include "basics/print.h"
#include "basics/basic_operations.h"
#include "solvers/basic_solver.h"
#include "test.h"


int main(void) {
    int sudoku[9][9];
    set_sudoku(sudoku);

    // Will be true if possible_positions removes a single number
    bool is_removed;
    int possible_positions[9][9][9];
    fill_with_every_number(possible_positions);

    const int to_solve = set_to_solve(sudoku);
    int solved = 0;

    printf("Start:\n");
    print_sudoku(sudoku);

    do {
        is_removed = false;
        solve_basic(sudoku, possible_positions, &is_removed, &solved);
    } while (is_removed);

    print_sudoku(sudoku);
    printf("Solved %d/%d:\n\n", solved, to_solve);

    return 0;
}
