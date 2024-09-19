//
// Created by ziclaud on 08/08/24.
//

#include <stdio.h>
#include <assert.h>
#include "test.h"

#include <stdlib.h>
#include <string.h>

#include "../basics/basics.h"
#include "../basics/print.h"

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
            sudoku[i][j] = VOID_CELL;
            print_sudoku(sudoku);
            printf("Enter an integer (between 0 and 9): ");
            assert(scanf("%d", &number));
            assert(number >= 0 && number <= 9);
            sudoku[i][j] = number;
        }
    }
}

/// Reads sudoku from input
void set_custom_sudoku_string(int sudoku[9][9]) {
    char *numbers = malloc(81 * sizeof(char) + 1);
    _fill_with_zeros(sudoku);
    printf("Enter the 81 character string containing only numbers:\n");
    assert(scanf("%s", numbers));
    assert(strlen(numbers) == 81);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = numbers[i * 9 + (j + 1) - 1] - '0';
        }
    }
    free(numbers);
}

void set_sudoku_easy(int sudoku[9][9]) {
    const int s[9][9] = {
        {0, 1, 4, 0, 0, 8, 3, 6, 0},
        {0, 0, 6, 0, 3, 0, 1, 0, 8},
        {0, 7, 8, 1, 0, 0, 9, 0, 4},
        {0, 0, 0, 8, 0, 2, 0, 3, 1},
        {0, 4, 7, 3, 1, 5, 8, 9, 0},
        {8, 3, 0, 6, 0, 4, 0, 0, 0},
        {7, 0, 2, 0, 0, 3, 6, 1, 0},
        {4, 0, 5, 0, 6, 0, 7, 0, 0},
        {0, 6, 3, 9, 0, 0, 5, 4, 0}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = s[i][j];
        }
    }
}

void set_sudoku_med(int sudoku[9][9]) {
    // TODO
    const int s[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
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


void set_sudoku_hard(int sudoku[9][9]) {
    // TODO
    const int s[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
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
