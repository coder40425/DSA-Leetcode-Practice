/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
  
Example 2:
Input: s = "a"
Output: [["a"]]             */

/*
##APPROACH:-
-Using Recursion & Backtracking
-A function to check if a string is palindrome or not.
-Store all possible combinations in path one by one & push them into result.

      TIME COMPLEXITY:- O(2^n * n)     SPACE COMPLEXITY:- O(n * n)   */

class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--]) return false;
        return true;
    }

    void backtrack(int start, string s, vector<string>& path) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path);
                path.pop_back();  // backtrack
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(0, s, path);
        return result;
    }
};
 
