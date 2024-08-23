#include <stdbool.h>
#include <stdio.h>
#include "basics/print.h"
#include "basics/basic_operations.h"
#include "basics/poss_pos_operations.h"
#include "solvers/basic_solver.h"
#include "solvers/med_solver.h"
#include "examples/test.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_result(int sudoku[9][9], int solved_cells, int to_solve) {
    print_sudoku(sudoku);
    if (has_errors(sudoku)) {
        printf(ANSI_COLOR_YELLOW "WARNING: Errors found" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_RED "Solved %d/%d:\n"ANSI_COLOR_RESET "\n", solved_cells, to_solve);
    } else {
        if (solved_cells == to_solve) {
            printf("Solved %d/%d:\n\n", solved_cells, to_solve);
        } else {
            printf(ANSI_COLOR_CYAN "Solved %d/%d:\n"ANSI_COLOR_RESET "\n", solved_cells, to_solve);
        }
    }
}

int main(void) {
    int sudoku[9][9];
    set_custom_sudoku_string(sudoku);

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
