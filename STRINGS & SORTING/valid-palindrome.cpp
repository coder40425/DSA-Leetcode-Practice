/* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
  
Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
  
Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


APPROACH:-
USE TWO POINTERS FROM BOTH ENDS OF THE STRING.

SKIP NON-ALPHANUMERIC CHARACTERS USING ISALNUM().

CONVERT BOTH CHARACTERS TO LOWERCASE  (BY USING tolower()) FOR CASE-INSENSITIVE COMPARISON.

IF ANY MISMATCH OCCURS, RETURN FALSE.

IF LOOP COMPLETES WITHOUT MISMATCH, RETURN TRUE.


TIME COMPLEXITY :- O(N)
SPACE COMPLEXITY :- O(1)                                                         */



class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right && !isalnum(s[left])){      //  ! isalnum() means its neither a alphabetic nor a numeric character
                left++;
            }
            while(left<right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){            //using tolower() to convert the character into lowercase
                return false;
            }
            left++;                               //when s[left] == s[right], then move inward.
            right--;
        }
        return true;
    }
};
