/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".       */

/*
##APPROACH:-
-Using Sliding Window
-Maintain a frequency count of characters in p.
-Use a sliding window of p.size() over s.
-Keep updating frequency counts as the window slides:
  -Add the new character entering the window,
  -Remove the character leaving the window.
-Compare window frequency with p’s frequency; if equal, record start index.

     Time Complexity: O(N)     Space Complexity: O(1)                  */

//my solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        if(s.size() < p.size()) return result;

        vector<int>p_freq(26,0); //to count freq in p
        vector<int>window_freq(26,0);  //to count freq in window
        
        for(char ch: p){  //count freq of p
            p_freq[ch - 'a']++;
        }

            int windowSize = p.size();
            for(int i=0;i<s.size();i++){
                //count freq of window
                window_freq[s[i] - 'a']++;
            if(i >= windowSize){
                //slide the window
                window_freq[s[i - windowSize] - 'a']--;
            }
            //match frequencies, if matched -> anagram
            if(window_freq == p_freq){
                result.push_back(i - windowSize + 1);  //store the first index of the found anagram
            }
        }
        return result;
    }
};
