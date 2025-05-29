/* Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
 

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"
  
Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

APPROACH:-
-WE WILL USE STRINGSTREAM SS TO SPLIT THE WORDS.
-WE WILL CREATE VECTOR<INT> WORDS, AND PUSH BACK INTO IT AFTER SPLITTING THE WORDS.
-THEN, REVERSE THE WORDS IN THE STRING WORDS.
-AFTER THAT INITIALIZE A STRING RESULT, AND JOIN WORDS INTO THIS STRING USING LOOP (i.e. RESULT = RESULT + WORDS[i])
-TO GIVE A SPACE AFTER EVERY WORD IN RESULT, PUT A CONDITION IF (i != WORDS.SIZE() -1 ) , RESULT = RESULT + " " 
-RETURN RESULT.

  TIME COMPLEXITY- O(N)
  SPACE COMPLEXITY- O(N)                                        */

class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
       string word;
       vector<string>words;
       while(ss>>word){
        words.push_back(word);
       }
       reverse(words.begin(),words.end());
       string result;
       for(int i=0;i<words.size();i++){
        result+=words[i];
        if(i!=words.size()-1){
            result+=" ";
        }
        
       }
       return result;
       } 
};
 
