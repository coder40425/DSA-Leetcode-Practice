/* NEW TITLE OF THE QUESTION IS: "FIND THE INDEX OF THE FIRST OCCURENCE IN A STRING"

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

APPROACH:
-WE WILL DO IT WITH APPROACH OF SUBSTRING MATCHING.
-FIRST OF ALL, INITIALISE 'n' AS THE SIZE OF HAYSTACK AND 'm' AS THE SIZE OF NEEDLE.
-NOW LOOP THROUGH EACH INDEX IN HAYSTACK
   [LOOP WILL GO TILL (<= n - m), BECAUSE AFTER THAT ANY OTHER SUBSTRING OF HAYSTACK WILL NOT MATCH THE SIZE OF NEEDLE,]
   [WHICH MEANS NEEDLE WILL NOT BE FOUND AFTER THAT INDEX.]
-AT EACH INDEX, CHECK IF THERE IS A SUBSTRING OF SIZE M WHICH IS EQUAL TO NEEDLE IS PRESENT OR NOT.
-IF YES, RETURN THAT INDEX. (IT WILL BE THE FIRST OCCURENCE)
-IF LOOP ENDS, AND NO MATCH WAS FOUND, RETURN -1.



   TIME COMPLEXITY- O(n * m)   
   SPACE COMPLEXITY-O(m)     //AS SUBSTR(i , m) CREATES A NEW STRING EACH TIME.
                                                                                                */


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
      
        if(m==0){
            return 0;        //edge case
        }
      
        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m)==needle){
                return i;
            }
        }
        return -1;
    }
};
