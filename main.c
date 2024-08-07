#include <stdio.h>

int s1[9][9] = {
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
int s2[9][9];
int s3[9][9];
int s4[9][9];


void fill_with_zeros(int s[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = 0;
        }
    }
}

void print_sudoku(int s[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if ((j + 1) % 3 == 0 && j != 8) {
                printf("%d|", s[i][j]);
            } else {
                printf("%d ", s[i][j]);
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i != 8) {
            printf("-----------------\n");
        }
    }
}

int main(void) {
    fill_with_zeros(s2);
    fill_with_zeros(s3);
    fill_with_zeros(s4);

    print_sudoku(s1);

    return 0;
}
