/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
  
Example 2:
Input: nums = [0]
Output: [[],[0]]                */

/*
##APPROACH:-
-Using Recursion & Backtracking
-Requires sorting + skipping duplicates
-Store all possible permutations in subsets one by one & push them into result.

      TIME COMPLEXITY:- O(2^n)     SPACE COMPLEXITY:- O(n)   */
  
class Solution {
public:
     vector<vector<int>> result;
    void solve(int index, vector<int>& nums, vector<int>& subset) {
        result.push_back(subset);  // No base case needed as we want all prefix states

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates at same tree level
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Include current element
            subset.push_back(nums[i]);

            // Move forward
            solve(i + 1, nums, subset);

            // Backtrack
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  //for handling duplicates
        vector<int> subset;

        solve(0, nums, subset);
        return result;
    }
};
