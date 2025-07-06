/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, 
 starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.       */

/*
##APPROACH:-
-Using Recursion + Memorization (using unordered maps)
-Logic:- ways(n) = ways(n-1) + ways(n-2).

         TIME COMPLEXITY:-O(n)   SPACE COMPLEXITY:- O(n)           */

//my solution
class Solution {
public:
    unordered_map<int, int>dp; //to store computed results
   int fib(int n) {
    if (n == 1) return 1;
    if(n <= 0) return 0;

    if(dp.count(n)) return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    
    return dp[n];
    }
};
