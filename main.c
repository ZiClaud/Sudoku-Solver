#include <stdbool.h>
#include <stdio.h>
#include "basics/print.h"
#include "basics/basic_operations.h"
#include "basics/poss_pos_operations.h"
#include "solvers/basic_solver.h"
#include "solvers/med_solver.h"
#include "examples/test.h"

int main(void) {
    int sudoku[9][9];
    set_custom_sudoku(sudoku);

    // Will be true if poss_pos removes a single number
    bool is_changed;
    int poss_pos[9][9][9];
    fill_with_every_number(poss_pos);

    const int to_solve = set_to_solve(sudoku);
    int solved_cells = 0;

    printf("Start:\n");
    print_sudoku(sudoku);


    do {
        do {
            is_changed = false;
            solve_basic(sudoku, poss_pos, &is_changed, &solved_cells);
        } while (is_changed);
        solve_med(sudoku, poss_pos, &is_changed, &solved_cells);
    } while (is_changed);

    print_result(sudoku, solved_cells, to_solve);

    return 0;
}
