/* Given an integer n, return true if it is a power of two. Otherwise, return false.
  An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1
  
Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16                */

/*
#APPROACH:-
-A number n is a power of two if it is positive and has exactly one set bit in binary.
-Edge cases:  
   n = 0 -> return false,  n < 0 -> return false  (Already handled by n > 0)
     
         TIME COMPLEXITY:- O(1)
         SPACE COMPLEXITY:- O(1)                      */


class Solution {
public:
    bool isPowerOfTwo(int n) {
        //edge case: n=0 or if n is negative integer 
        return n > 0 && (n & (n-1)) == 0;
    }
};
