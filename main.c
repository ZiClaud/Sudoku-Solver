#include <stdio.h>

int sudoku[9][9] = {
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


void fill_with_zeros(int s[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = 0;
        }
    }
}

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

    // printf("%d", s[1][0]); // 4
    // printf("%d", s[0][1]); // 1
}

int main(void) {
    print_sudoku(sudoku);

    return 0;
}
