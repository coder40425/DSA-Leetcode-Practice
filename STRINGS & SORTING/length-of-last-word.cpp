/* Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

APPROACH:-
-AS WE HAVE TO COUNT THE NLENGTH OF THE LAST WORD.
-SO WE WIILL START FROM THE END (LAST INDEX)
-WHILE S[i] IS SPACE -> MOVE LEFT
-WHHEN S[i] IS NOT SPACE -> COUNT LENGTH (i.e. LENGTH++) AND THEN MOVE LEFT.
-RETURN LENGTH


     TIME COMPLEXITY- O(N)
     SPACE COMPLEXITY-O(1)                                                                   */

  

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        int i=s.length()-1;              //POINTER i IS AT THE LAST INDEX NOW

        while(i>=0 && s[i]==' '){
            i--;
        }
         while(i>=0 && s[i]!=' '){
            length++;
            i--;
        }
        return length;
    }
};
