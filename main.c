#include <stdbool.h>
#include <stdio.h>
#include "basics/print.h"
#include "basics/basic_operations.h"
#include "solvers/basic_solver.h"
#include "solvers/med_solver.h"
#include "test.h"


int main(void) {
    int sudoku[9][9];
    set_sudoku_ny_med(sudoku);

    // Will be true if possible_positions removes a single number
    bool is_changed;
    int possible_positions[9][9][9];
    fill_with_every_number(possible_positions);

    const int to_solve = set_to_solve(sudoku);
    int solved = 0;

    printf("Start:\n");
    print_sudoku(sudoku);

    do {
        is_changed = false;
        solve_basic(sudoku, possible_positions, &is_changed, &solved);
        solve_med(sudoku, possible_positions, &is_changed, &solved);
    } while (is_changed);

    print_sudoku(sudoku);
    printf("Solved %d/%d:\n\n", solved, to_solve);

    return 0;
}
