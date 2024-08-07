#include <stdbool.h>
#include <stdio.h>

// Will be true if possible_positions changes a single number
bool number_was_removed = false;

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

int possible_positions[9][9][9];

void fill_with_zeros(int s[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = 0;
        }
    }
}

void fill_with_every_number(int s[9][9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            for (int i = 0; i < 9; ++i) {
                s[row][col][i] = i + 1;
            }
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

void _remove_row(int poss[9][9][9], int row, int col) {
    // If item in row gets removed, -> number_was_removed = true
}

void _remove_col(int poss[9][9][9], int row, int col) {
    // If item in col gets removed, -> number_was_removed = true
}

void remove_row_and_col(int poss[9][9][9], int row, int col) {
    _remove_row(poss, row, col);
    _remove_col(poss, row, col);
}

void remove_square(int poss[9][9][9], int row, int col) {
    // TODO
    // If item in square gets removed, -> number_was_removed = true
}

void solve_easy(int s[9][9]) {
    number_was_removed = false;
    // Checks rows and cols
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (s[row][col] == 0) {
                remove_row_and_col(possible_positions, row, col);
            } else {
                for (int i = 0; i < 9; ++i) {
                    possible_positions[row][col][i] = -1;
                }
            }
        }
    }

    // Checks the square
    // TODO


    // Add all possible positions where theres just a number that fits there
    int count;
    for (int row = 0; row < 9; ++row) {
        count = 0;
        for (int col = 0; col < 9; ++col) {
            for (int i = 0; i < 9; ++i) {
                if (possible_positions[row][col][i]) {
                    count++;
                }
            }
        }
        if (count == 1) {
            // TODO -> Set the only number in sudoku
        }
    }
}

int main(void) {
    print_sudoku(sudoku);
    fill_with_every_number(possible_positions);

    do {
        solve_easy(sudoku);
    } while (number_was_removed);

    print_sudoku(sudoku);
    // print_sudoku(possible_positions);


    return 0;
}
