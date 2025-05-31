/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
  
 (An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.)
  
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false


# WE WILL DO IT USING TWO DIFFERENT APPROACHES.
  
APPROACH 1:-
-USING UNORDERED MAP
-COUNT THE FREQUENCY OF CHARACTERS OF BOTH THE STRINGS
-IF FREQ1 == FREQ2 (MEANS ALL THE CHARACTERS IN STRING 'S' ARE PRESENT IN STRING 'T' WITH THE SAME FREQUENCY), THEN RETURN TRUE (IT IS A ANAGRAM). 

  TIME COMPLEXITY- O(N)
  SPACE COMPLEXITY- O(K) (K IS THE NO. OF UNIQUE CHARACTERS (MAX 26, FOR LOWERCASE))                     */

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1,freq2;
        for(char c: s){          //COUNTING FOR STRING S
            freq1[c]++;
        }
        for(char c: t){         //COUNTING FOR STRING T
            freq2[c]++;
        }
        if(freq1==freq2){       
            return true;
        }
        return false;
    }
};

/*
APPROACH 2:-
-USING FREQUENCY ARRAY
  [A FREQUENCY ARRAY IS A FIXED SIZE ARRAY (USUALLY SIZE- 26 FOR LOWERCASE LETTERS)]
  [IT WORKS FAST WHEN INPUT RANGE IS KNOWN (LIKE LOWERCASE LETTERS)
-IT IS COMPARATIVELY BETTER APPROACH IN TERMS OF EXTRA SPACE.
-WE INITIALISE A FREQUENCY ARRAY OF SIZE 26. (INT FREQ[26] = {0})
-FOR EACH CHARACTER IN STRING S, INCREMENT ITS CORRESPONDING COUNT IN ARRAY.
-THEN, FOR EACH CHARACTER IN STRING T, DECREASE ITS FREQUENCY COUNT IN THE ARRAY.
-IF BOTH STRINGS HOLD THE SAME CHARACTERS WITH SAME FREQUENCIES, THEN AFTER ADDING FOR S AND SUBTRACTING FOR T, ALL VALUES IN THE FREQUENCY ARRAY SHOULD BE ZERO.
-IF ANY VALUE IS NOT ZERO, NOT AN ANAGRAM.

         TIME COMPLEXITY-  O(N)
         SPACE COMPLEXITY- O(1) [AS THERE IS ONLY A FIXED SIZE OF ARRAY]                                         */

  
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={0};
        for(char c: s){
            freq[c-'a']++;         //INCREASE COUNT FOR EACH CHARACTER IN S
        }
        for(char c: t){
            freq[c-'a']--;             //DECREASE COUNT FOR EACH CHARACTER IN T
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){              // IF IT IS A VALID ANAGRAM, THEN ALL WILL BE ZERO
                return false;
            }
        }
            return true;
        }
