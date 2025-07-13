/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above        */

/*
##APPROACH:-
-Using Recursion & Backtracking + Hashing (to attack tracked columns and diagnols)

    TIME COMPLEXITY:- O(n!)    SPACE COMPLEXITY:- O(n^2)              */

//MY SOLUTION
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // Initial empty board
        vector<string> board(n, string(n, '.'));

        // Hash arrays to track attacked columns and diagonals
        vector<int> leftRow(n, 0);              // Columns
        vector<int> upperDiagonal(2 * n - 1, 0); // '/' diagonal (n - 1 + col - row)
        vector<int> lowerDiagonal(2 * n - 1, 0); // '\' diagonal (row + col)

        // Start solving from column 0
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }

private:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftRow,
               vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal,
               int n) {
        
        // Base Case: All columns filled
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            // Check if placing a queen is safe
            if (leftRow[row] == 0 &&
                lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Move to next column
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack (remove queen)
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
};
