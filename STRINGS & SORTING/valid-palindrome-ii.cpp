/* Given a string s, return true if the s can be palindrome after deleting at most one character from it.


Example 1:
Input: s = "aba"
Output: true
  
Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
  
Example 3:
Input: s = "abc"
Output: false


APPROACH :-

START TWO POINTERS FROM BEGINNING AND END OF THE STRING.

IF A MISMATCH OCCURS, TRY SKIPPING LEFT OR RIGHT CHARACTER.

CHECK IF EITHER NEW SUBSTRING IS A PALINDROME.

USE WHILE LOOPS TO VERIFY BOTH CASES (AFTER SKIPPING ONE CHARACTER).

IF EITHER CASE RETURNS TRUE, IT’S A VALID PALINDROME.

IF NO MISMATCH AT ALL, STRING IS ALREADY A PALINDROME.


TIME COMPLEXITY :- O(N)
SPACE COMPLEXITY :- O(1)
                                                                                    */



class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try skipping left or right
                int l1 = left + 1, r1 = right;
                int l2 = left, r2 = right - 1;

                bool valid1 = true, valid2 = true;

                while (l1 < r1) {
                    if (s[l1] != s[r1]) {
                        valid1 = false;
                        break;
                    }
                    l1++;
                    r1--;
                }

                while (l2 < r2) {
                    if (s[l2] != s[r2]) {
                        valid2 = false;
                        break;
                    }
                    l2++;
                    r2--;
                }

                return valid1 || valid2;
            }
            left++;
            right--;
        }

        return true;
    }
};
 
