#include <stdio.h>
#include "print.h"
#include "basics.h"
#include "basic_operations.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
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

void print_sudoku(int s[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if ((col + 1) % 3 == 0 && col != 8) {
                if (s[row][col] == VOID_CELL)
                    printf("X|");
                else
                    printf("%d|", s[row][col]);
            } else {
                if (s[row][col] == VOID_CELL)
                    printf("X ");
                else
                    printf("%d ", s[row][col]);
            }
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row != 8) {
            printf("-----------------\n");
        }
    }

    printf("\n\n");
}
