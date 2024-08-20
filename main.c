#include <stdbool.h>
#include <stdio.h>
#include "basics/print.h"
#include "basics/basic_operations.h"
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

void print_result(int sudoku[9][9], int solved, int to_solve) {
    print_sudoku(sudoku);
    if (has_errors(sudoku)) {
        printf(ANSI_COLOR_YELLOW "WARNING: Errors found" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_RED "Solved %d/%d:\n"ANSI_COLOR_RESET "\n", solved, to_solve);
    } else {
        if (solved == to_solve) {
            printf("Solved %d/%d:\n\n", solved, to_solve);
        } else {
            printf(ANSI_COLOR_CYAN "Solved %d/%d:\n"ANSI_COLOR_RESET "\n", solved, to_solve);
        }
    }
}

int main(void) {
    int sudoku[9][9];
    set_custom_sudoku_string(sudoku);

    // Will be true if possible_positions removes a single number
    bool is_changed;
    int possible_positions[9][9][9];
    fill_with_every_number(possible_positions);

    const int to_solve = set_to_solve(sudoku);
    int solved = 0;

    printf("Start:\n");
    print_sudoku(sudoku);

    do {
        do {
            is_changed = false;
            solve_basic(sudoku, possible_positions, &is_changed, &solved);
        } while (is_changed);
        solve_med(sudoku, possible_positions, &is_changed, &solved);
    } while (is_changed);

    print_result(sudoku, solved, to_solve);

    return 0;
}
