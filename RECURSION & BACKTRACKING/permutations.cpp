/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]         */

/*
##APPROACH:-
-Using Recursion & Backtracking
-Store all possible permutations in temp one by one & push into result.
-Maintain "used" to store the elements which are used.

      TIME COMPLEXITY:- O(n * n!)     SPACE COMPLEXITY:- O(n * n!)           */

class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& used){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                used[i] = true;
                temp.push_back(nums[i]);

                solve(nums, temp, used);

                //backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<bool> used(nums.size(), false);
        solve(nums, temp, used);
        return result;
    }
};
