/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
  // refer to actual problem to see the mapping of digits to letters 

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]      */

/*
##APPROACH:-
-Store digit -> letter mapping in hashmaps.
-Explore all combinations by recursively building strings, one digit at a time.
-When reach end of the string, save the combination.
-Backtrack to try other possibilities.

    TIME COMPLEXITY:- O(4^n)     SPACE COMPLEXITY:- O(4^n)             */

//my solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string path;
        
        backtrack(0, digits, phone, path, result);

        return result;
    }

    void backtrack(int index, const string& digits,
                   unordered_map<char, string>& phone,
                   string& path, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        for (char c : phone[digits[index]]) {
            path.push_back(c);
            backtrack(index + 1, digits, phone, path, result);
            path.pop_back();  // Backtrack
        }
    }
};
