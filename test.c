//
// Created by ziclaud on 08/08/24.
//

#include <stdio.h>
#include <assert.h>
#include "test.h"
#include "print.h"

void _fill_with_zeros(int s[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = 0;
        }
    }
}

/// Reads sudoku from input
void set_custom_sudoku(int sudoku[9][9]) {
    int number;
    _fill_with_zeros(sudoku);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("Enter an integer (between 0 and 9): ");
            assert(scanf("%d", &number));
            assert(number >= 0 && number <= 9);
            sudoku[i][j] = number;
            print_sudoku(sudoku);
        }
    }
}

void set_sudoku(int sudoku[9][9]) {
    const int s[9][9] = {
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

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = s[i][j];
        }
    }
}

void set_sudoku_ny(int sudoku[9][9]) {
    const int s[9][9] = {
        {0, 5, 0, 6, 0, 1, 0, 0, 8},
        {0, 2, 4, 9, 8, 0, 3, 0, 0},
        {9, 8, 0, 2, 0, 0, 7, 4, 0},
        {0, 0, 0, 7, 0, 5, 0, 0, 4},
        {5, 0, 8, 0, 0, 6, 0, 9, 0},
        {7, 0, 0, 0, 9, 4, 6, 5, 0},
        {1, 0, 6, 0, 0, 0, 4, 8, 3},
        {0, 0, 0, 4, 3, 9, 0, 0, 1},
        {0, 3, 2, 0, 6, 0, 0, 0, 0}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = s[i][j];
        }
    }
}

void set_sudoku_test(int sudoku[9][9]) {
    const int s[9][9] = {
        {0, 0, 0, 6, 0, 1, 0, 0, 0},
        {0, 0, 0, 9, 8, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = s[i][j];
        }
    }
}
