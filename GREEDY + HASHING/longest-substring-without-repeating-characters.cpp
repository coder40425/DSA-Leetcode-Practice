/*Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
  
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.      */

/*
##APPROACH:-
-Hashmap + Sliding Window
-Traverse the string, while adding characters in the map.
-If character 'ch' is already in map & its last index is within the current window, then slide the window (start = map[ch] + 1).
-Update the last seen index of character (map[ch] = i).
-Store the longest substring.                                           

  TIME COMPLEXITY:- O(N)       SPACE COMPLEXITY:- O(1)                        */

//MY SOLUTION
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int longest=0, start=0;
       
        for(int i=0;i<s.length();i++){
             char ch = s[i];
             if(map.find(ch)!=map.end() && map[ch]>=start){
                start= map[ch]+1;
             }

             map[ch] = i;
             longest = max(longest,i - start + 1);
        }
        return longest;
    }
};
