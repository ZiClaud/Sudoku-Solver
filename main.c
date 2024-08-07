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

int sudoku2[9][9] = {
    {1, 2, 3, 4, 5, 0, 7, 8, 9},
    {2, 3, 4, 5, 6, 7, 8, 9, 1},
    {3, 4, 5, 6, 7, 8, 9, 1, 2},
    {4, 5, 6, 7, 8, 9, 1, 2, 3},
    {5, 6, 7, 8, 9, 1, 2, 3, 4},
    {6, 7, 8, 9, 1, 2, 3, 4, 5},
    {7, 8, 9, 1, 2, 3, 4, 5, 6},
    {8, 9, 1, 2, 3, 4, 5, 6, 7},
    {9, 1, 2, 3, 4, 5, 6, 7, 8}
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

    printf("\n\n");

    // printf("%d", s[1][0]); // 4
    // printf("%d", s[0][1]); // 1
}

bool contains(int list[9], int val) {
    for (int i = 0; i < 9; ++i) {
        if (list[i] == val) {
            return true;
        }
    }
    return false;
}

void _remove(int list[9], int val) {
    list[val - 1] = 0;
}

void _remove_row(int s[9][9], int poss[9][9][9], int row, int col) {
    // If item in row gets removed, -> number_was_removed = true
    for (int c = 0; c < 9; ++c) {
        if (contains(poss[row][col], s[row][c])) {
            number_was_removed = true;
            _remove(poss[row][col], s[row][c]);
        }
    }
}

void _remove_col(int s[9][9], int poss[9][9][9], int row, int col) {
    // If item in col gets removed, -> number_was_removed = true
    // TODO
}

void remove_row_and_col(int s[9][9], int poss[9][9][9], int row, int col) {
    _remove_row(s, poss, row, col);
    _remove_col(s, poss, row, col);
}

void remove_square(int s[9][9], int poss[9][9][9], int row, int col) {
    // If item in square gets removed, -> number_was_removed = true
    // TODO
}

void solve_easy(int s[9][9]) {
    number_was_removed = false;
    // Checks rows and cols
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (s[row][col] == 0) {
                remove_row_and_col(s, possible_positions, row, col);
            } else {
                // Sets all values to -1
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
    int val;
    for (int row = 0; row < 9; ++row) {
        count = 0;
        val = -1;
        for (int col = 0; col < 9; ++col) {
            for (int i = 0; i < 9; ++i) {
                if (possible_positions[row][col][i]) {
                    count++;
                    val = possible_positions[row][col][i];
                }
            }
            if (count == 1) {
                s[row][col] = val;
            }
        }
    }
}

int main(void) {
    printf("Start:\n\n");
    print_sudoku(sudoku2);
    fill_with_every_number(possible_positions);

    do {
        solve_easy(sudoku2);
    } while (number_was_removed);


    printf("Solved:\n\n");
    print_sudoku(sudoku2);
    // print_sudoku(possible_positions);


    return 0;
}
