/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
  
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


APPROACH:-
-START WITH THE FIRST STRING AS YOUR PREFIX.
-LOOP THROUGH THE REST OF THE STRINGS.
-WHILE THE CURRENT STRING DOES NOT START WITH PREFIX, SHRINK THE PREFIX (i.e. REMOVE THE LAST CHARACTER)
-RETURN PREFIX, WHEN LOOP ENDS.

                       
                          (N -> NO. OF STRINGS, M-> LENGTH OF LONGEST STRING)
    TIME COMPLEXITY:- O(N * M)   [WORST CASE: COMPARE EACH CHARACTER OF EACH STRING]
    SPACE COMPLEXITY:- O(1)      [AUXILIARY SPACE]                                                                        */



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";               // edge case (not needed here)
        }
        
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(prefix)!=0){
                prefix=prefix.substr(0,prefix.length()-1);
            }
        }
        return prefix;
    }

};
