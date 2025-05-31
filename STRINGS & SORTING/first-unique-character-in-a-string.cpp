/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1


APPROACH:-
-WE WILL DO IT USING FREQUENCY ARRAY. (BEST APPROACH FOR LOWERCASE LETTERS)
-WE WILL INITIALISE A ARRAY OF SIZE 26. (INT FREQ[26]  = {0})
-THEN CALCULATE THE FREQUENCY OF ALL THE CHARACTERS IN STRING S.
-NOW START A LOOP, AND RETURN THE INDEX OF THE FIRST CHARACTER WITH FREQUENCY EQUAL TO 1. (FREQ = 1 MEANS ITS NON REPEATING AND APPEARS ONLY ONCE)
            [WE CAN DO IT USING HASHMAPS ALSO, BUT FREQUENCY ARRAY APPROACH IS FASTER AND BETTER FOR SPACE OPTIMISATION)]


   TIME COMPLEXITY- O(N)
   SPACE COMPLEXITY-O(1)  (FIXED SIZE OF ARRAY)
                                                                                                          */


class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};             //INITIALISING FREQ. ARRAY
      
        for(char c: s){                   
            freq[c - 'a']++;          //CALCULATING FREQUENCY OF STRING S
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==1){
                return i;              //RETURN THE INDEX OF THE FIRST CHARACTER WITH FREQ = 1
        } 
        }
        return -1;              // OTHERWISE RETURN 1

    }
};
