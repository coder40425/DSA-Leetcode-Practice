/* Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
   Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false
  
Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false
  
Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true                                        */

/*
#APPROACH:-
-Using Hashmaps.
-Count frequency of each character in magazine.
-Decrease count while scanning ransomNote. 
-If any letter's count becomes negative, return false.

    TIME COMPLEXITY:- O(N + M) [N-> length of magazine, M-> Length of ransomNote]
    SPACE COMPLEXITY:- O(1)                                                            */

//MY SOLUTION
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(char ch: magazine){    //count frequency of each character in magazine
            freq[ch]++;
        }
        for(char ch: ransomNote){  //check if ransom note can be built from magazine
            if(freq[ch]==0){
                return false;    //not enough chars
            }
          
            freq[ch]--;     //use one
        }
        return true;     //all chars matched
    }
};
