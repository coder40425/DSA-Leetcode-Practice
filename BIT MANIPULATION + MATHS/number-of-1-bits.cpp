/* Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.                       */

/*
#APPROACH:-
-Each (n & (n-1)) operation removes 1 set bit, so by counting how many times this happens until n=0, we get the total number of 1s.
-Basically the final answer is the number of iterations until n becomes 0.

        TIME COMPLEXITY:- O(NO. OF SET BITS)
        SPACE COMPLEXITY:- O(1)                                   */


class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
};
