/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
  
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"


APPROACH:-
-ANALYSE THE PATTERN, AND CHECK FOR ROWS 5,6 ETC.
-HANDLE BASE CASE 
    IF NUMROWS==1 , RETURN S (NO ZIGZAG POSSSIBLE)
-CREATE A VECTOR OF EMPTY STRINGS.(ONE FOR EACH ROW)
-TRAVERSE THE STRING.
-WE MOVE DOWN ROW BY ROW, UNTILL WE HIT THE BOTTOM ROW.
-THEN GO UP DIAGNALLY, ONE ROW AT A TIME, UNTIL WE HIT THE TOP.
-THIS PATTERN REPEATS.
-AFTER LOOP, COMBINE ALL ROWS INTO ONE FINAL STRING.

  TIME COMPLEXITY:- O(N)      (EACH CHARACTER IS VISITED EXACTLY ONCE)   [ N -> S.LENGTH() ]
  SPACE COMPLEXITY:- O(N)     (N CHARACTERS STORED ACROSS NUMROWS STRINGS IN THE ROWS VECTOR)                       */
  

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s; // Edge case
        }

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            // Flip direction at top or bottom row
            if (currRow == 0 || currRow == numRows - 1){
                goingDown = !goingDown;
            }

            // Always move to next row
            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows){
            result += row;
        }

        return result;
    }
};





  
