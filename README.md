# Sudoku Solver

This Sudoku Solver allows you to solve puzzles using two different modes: Faster Mode (default) for quick solving and
Easy/Beginner-Friendly Mode for a more guided experience.

## Getting Started

Select your preferred mode by responding to the first prompt with 'Y' for Faster Mode or 'N' for Beginner-Friendly Mode.

## Modes

### - Faster Mode (Default)

This mode solves the puzzle quickly based on the provided input string.

<details>
<summary><b>Click to see an example</b></summary>

```
Enter the 81-character string containing only numbers:
980376410603000070000450800006000048208164000017090060020081900000007000060902704

9 8 0|3 7 6|4 1 0
6 0 3|0 0 0|0 7 0
0 0 0|4 5 0|8 0 0
-----------------
0 0 6|0 0 0|0 4 8
2 0 8|1 6 4|0 0 0
0 1 7|0 9 0|0 6 0
-----------------
0 2 0|0 8 1|9 0 0
0 0 0|0 0 7|0 0 0
0 6 0|9 0 2|7 0 4
```

</details>

### - Easy/Beginner Friendly Mode

This mode allows step-by-step input, providing guidance as you fill in the puzzle.

<details>
<summary><b>Click to see an example</b></summary>

```
X 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
-----------------
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
-----------------
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0

Enter an integer (between 0 and 9): 9


9 X 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
-----------------
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
-----------------
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0
0 0 0|0 0 0|0 0 0

Enter an integer (between 0 and 9):
(...)
```

</details>

## Testing the Solver

You can test the Sudoku Solver using the example puzzles located in the `examples` directory. These examples are
provided in `*.json` files.

## Solver Outcomes

- White Text: Puzzle solved successfully.
- Cyan Text: Could not complete the puzzle.
- Red Text: Errors were made while attempting to solve the puzzle.

## Acknowledgments

The Sudoku examples in the `examples` directory are sourced from [Open Sudoku](https://opensudoku.moire.org/).
