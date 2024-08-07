#include <stdio.h>
#include "print.h"

void print_sudoku(int s[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if ((col + 1) % 3 == 0 && col != 8) {
                printf("%d|", s[row][col]);
            } else {
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
