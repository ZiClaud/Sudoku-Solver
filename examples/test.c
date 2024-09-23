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

/// Reads sudoku from input (Beginner friendly mode)
void set_custom_sudoku_easy(int sudoku[9][9]) {
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

/// Reads sudoku from input (Faster mode)
void set_custom_sudoku_fast(int sudoku[9][9]) {
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

void set_custom_sudoku(int sudoku[9][9]) {
    printf("Fast setup? Y/n\n");
    char *answer = malloc(10 * sizeof(char) + 1);
    answer[0] = 'Y';
    assert(scanf("%s", answer));
    assert(strlen(answer) <= 10);

    if (answer[0] == 'n' || answer[0] == 'N') {
        printf("Fast setup\n");
        set_custom_sudoku_easy(sudoku);
    } else {
        printf("Easy setup\n");
        set_custom_sudoku_fast(sudoku);
    }

    free(answer);
}
