/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true                */

/*
#APPROACH:-
-For each cell (i, j) in the board, try to build the word.
-If the current cell matches the first charcater of word : recursively try its 4 neighbours for the next character.
-Mark the current cell as visited so its not reused.
-Backtrack (unmark visited cell) when done.

    TIME COMPLEXITY:- O(n * 3^L)    SPACE COMPLEXITY:- O(L)   [L -> length of words]       */

class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if(index == word.size()) return true; // base case: full word matched
        if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        // explore all 4 directions
        bool found = dfs(board, i+1, j, word, index+1) ||
                     dfs(board, i-1, j, word, index+1) ||
                     dfs(board, i, j+1, word, index+1) ||
                     dfs(board, i, j-1, word, index+1);

        board[i][j] = temp; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
