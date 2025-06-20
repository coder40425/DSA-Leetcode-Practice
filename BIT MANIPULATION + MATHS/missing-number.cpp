/* Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.   */


/*
##APPRPACH:- (XOR Trick)
-Initialize two XOR variables.
-xor1: Includes XOR of all expected numbers 0 to n
-xor2: Includes XOR of given numbers in the array
-Since a ^ a = 0, all matching elements cancel out
-Leftover value = missing number

     TIME COMPLEXITY:- O(N)
     SPACE COMPLEXITY:- O(1)                    */


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Initialize two XOR variables
        int xor1 = 0;  // XOR of all numbers from 0 to n
        int xor2 = 0;  // XOR of all elements in the array

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all elements in the input array
        for (int num : nums) {
            xor2 ^= num;
        }

        // The missing number is the XOR of these two results
        return xor1 ^ xor2;
    }
};
