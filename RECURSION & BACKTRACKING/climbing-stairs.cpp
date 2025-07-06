/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps                                               */

/*
##APPROACH:-
-Using Recursion + Memorization (using unordered maps)
-Logic:- ways(n) = ways(n-1) + ways(n-2).

         TIME COMPLEXITY:-O(n)   SPACE COMPLEXITY:- O(n)           */

class Solution {
public:
    unordered_map<int, int> dp;  //to store computed results
   int climbStairs(int n) {
    if (n == 0) return 1;
    if(n < 0) return 0;

    if(dp.count(n)) return dp[n];
    dp[n] = climbStairs(n-1) + climbStairs(n-2);
    
    return dp[n];
}
};
