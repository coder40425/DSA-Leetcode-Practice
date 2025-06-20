/* Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
  
Example 2:
Input: nums = [0]
Output: [[],[0]]                         */

/*
##APPROACH: (BITMASKING)
1. There are 2^n possible subsets of an array of size n.
2. We use numbers from 0 to 2^n - 1 as bitmasks to represent subsets.
3. For each number i, we check if the j-th bit is ON → if yes, include nums[j].
4. Store each built subset into the result vector.

  Time Complexity: O(n * 2^n) [Outer loop runs 2^n times, inner loop runs n times]
  Space Complexity: O(n * 2^n) [Because we store all 2^n subsets and each subset can be up to size n]                    */


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;  // Total subsets = 2^n
        vector<vector<int>> ans;

        // Loop through all possible masks from 0 to 2^n - 1
        for (int i = 0; i < total; ++i) {
            vector<int> subset;

            // Check each bit of i
            for (int j = 0; j < n; ++j) {
                // If j-th bit is ON in i, include nums[j]
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }

            ans.push_back(subset);  // Add current subset to the answer
        }

        return ans;
    }
};
