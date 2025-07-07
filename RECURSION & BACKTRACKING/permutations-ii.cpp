/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
 [[1,1,2],
 [1,2,1],
 [2,1,1]]                */

/*
##APPROACH:-
-Using Recursion & Backtracking
-Sort the array (ensures duplicates are adjacent).
-Store all possible permutations in temp one by one & push them into result.
-Maintain "used" to store the elements which are used.
-Skip:
   -if a number is already used.
   -if a number has appeared before in the array, and its not used.
-Return result

      TIME COMPLEXITY:- O(k * n)     SPACE COMPLEXITY:- O(k * n)      [k -> no. of unique pewrmutations]     */

class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& used){
        //base case
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;  //if already used
            if(i>0 && nums[i] == nums[i-1] && !used[i-1])  //if appeared before & was not used
                continue;

                used[i] = true;
                temp.push_back(nums[i]);

                solve(nums, temp, used);

                //backtrack
                temp.pop_back();
                used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<bool> used(nums.size(), false);
        solve(nums, temp, used);
        return result;
    }
};
