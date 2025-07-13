/*Write a program to solve a Sudoku puzzle by filling the empty cells.
 A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.                                                       */

/*
##APPROACH:-
-Backtracking: Try placing digits in empty cells. If stuck, backtrack and try a different digit.
-isValid(): Ensures Sudoku rules are followed: No duplicates in the current row, column, or 3×3 box.
-solve(): Fills one cell at a time and moves recursively until the board is valid.

    TIME COMPLEXITY:- O(9^n) [n -> no> of empty calls]         SPACE COMPLEXITY:- O(1)             */

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); 
    }
    // Recursive function to solve the board using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {               
            for (int j = 0; j < 9; j++) {           
                if (board[i][j] == '.') {           
                    for (char c = '1'; c <= '9'; c++) {  // Try digits from 1 to 9
                        if (isValid(board, i, j, c)) {   // Check if placing 'c' is valid
                            board[i][j] = c;             

                            // Recursively try to solve the rest of the board
                            if (solve(board))
                                return true;

                            // If not solvable, backtrack
                            board[i][j] = '.';
                        }
                    }

                    // If no digit from 1 to 9 fits, return false to trigger backtracking
                    return false;
                }
            }
        }

        // If all cells are filled correctly, return true
        return true;
    }

    // Helper function to check if placing 'c' at (row, col) is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the current row
            if (board[row][i] == c)
                return false;

            // Check the current column
            if (board[i][col] == c)
                return false;

            // Check the 3x3 subgrid
            int subgridRow = 3 * (row / 3) + i / 3;
            int subgridCol = 3 * (col / 3) + i % 3;
            if (board[subgridRow][subgridCol] == c)
                return false;
        }

        // If the digit can be placed safely
        return true;
    }
};
