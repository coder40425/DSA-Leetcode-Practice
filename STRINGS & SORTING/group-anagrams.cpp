/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.


Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
  
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
  
Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]


APPROACH:
-ANAGRAMS HAVE THE SAME CHARACTERS, JUST IN DIFFERENT ORDERS.
-SO, WE CAN USE SORTED STRING AS A KEY TO GROUP ALL ANAGRAMS.
-SO WE WILL USE UNORDERED MAPS TO STORE GROUPS, KEY -> SORTED VERSION OF STRING, VALUE->VECTOR OF STRINGS THAT MATCH THIS KEY.
-LOOP THROUGH EACH WORD IN THE INPUT.
-SORT THE WORD. (THIS IS THR KEY)
-ADD ORIGINAL WORD TO THE CORRESPONDING VECTOR IN THE MAPS.
-AFTER THE LOOP, COLLECT ALL VALUES FROM THE MAP.

   TIME COMPLEXITY:- O(N * KLOGK)  [N -> NO. OF STRINGS, K-> MAX. LENGTH OF A STRING (SORTING TAKES KLOGK)]
   SPACE COMPLEXITY:- O(N * K)     [FOR STORING STRINGS IN MAP]
                                                                                                                         */
  

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(string word: strs){
            string sortedword=word;
            sort(sortedword.begin(),sortedword.end());
            mp[sortedword].push_back(word);
        }
        vector<vector<string>> result;
        for(auto& pair: mp){
            result.push_back(pair.second);
        }
        return result;
    }
};
