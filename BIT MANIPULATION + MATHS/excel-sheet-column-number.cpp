/* Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Example 1:
Input: columnTitle = "A"
Output: 1
  
Example 2:
Input: columnTitle = "AB"
Output: 28                               */


/*
##APPROACH:-
-We treat the string as a number in base 26.
-For each character, we extract its value using c & 31 (bitwise trick for 'A'–'Z' → 1–26).
-We multiply the current result by 26 and add this value.
-Repeat for all characters from left to right.

      TIME COMPLEXITY: O(N) (N = Length of string)
      SPACE COMPLEXITY: O(1)                                           */

//my code
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result=0;
        for(char c: columnTitle){
            int val= c & 31;
          //int val= c - 'A' + 1;
            result= result * 26 + val;
        }
        return result;
    }
};
