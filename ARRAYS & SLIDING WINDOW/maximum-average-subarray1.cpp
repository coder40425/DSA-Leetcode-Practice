/*  You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000                                               */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSum = 0;
         // sliding window approach- O(N)
        // Step 1: Calculate initial window sum
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];     
        }

        int maxSum = windowSum;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};
