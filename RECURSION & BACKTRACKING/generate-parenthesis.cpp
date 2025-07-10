/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]      */

/*
#APPROACH:-
-Track the no. of open ( & close ) used.
-We can only add a ( if open < n
-We can only add a ) if close < open.

    TIME COMPLEXITY:- O(4^n / √n)      SPACE COMPLEXITY:- O(n * 4^n / √n)          */

class Solution {
public:
    vector<string> result;

    void solve(int open, int close, string temp, int n) {
        if(temp.length() == 2 * n) {
            result.push_back(temp);
            return;
        }

        if(open < n) {
            solve(open + 1, close, temp + '(', n);
        }
        if(close < open) {
            solve(open, close + 1, temp + ')', n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(0, 0, "", n);
        return result;
    }
};
