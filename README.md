## Sudoku Solver

### Example

<details>
    <summary>
        Using: set_custom_sudoku_string(sudoku); <br>
        <b>Faster</b> <i>(Default)</i>
    </summary>

```
Enter the 81 character string containing only numbers:
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

<details>
    <summary>
        Using: set_custom_sudoku(sudoku); <br>
        <b>Beginner Friendly</b> <i>(Change a line inside `main.c`) </i>
    </summary>

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

--- 

You can test the solver by using the strings found in the `*.json` files inside the directory `examples`.

- If the text at the end appears to be `white`, it was solved successfully
- If the text at the end appears to be `cyan`, it couldn't complete the whole sudoku
- If the text at the end appears to be `red`, there were some errors made while solving the sudoku

---

Sudoku examples in the directory `examples` are from https://opensudoku.moire.org/
