/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
 where the chosen numbers sum to target. You may return the combinations in any order.
 
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

/*
##APPROACH:-
-Using Recursion & Backtracking
-At every step we have two options:-
   -add the element itself
   -add the next element in the array
-At each level, as we move forward, update target (i.e. target = target - nums[index])
-Store all possible combinations in temp one by one & push them into result.

      TIME COMPLEXITY:- O(2^n)     SPACE COMPLEXITY:- O(n)   */

class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target, vector<int>& temp, int index){
        //base case 1
        if(target == 0){
            result.push_back(temp);
            return;
        }
        //base case 2
        if(target < 0 || index>= candidates.size()) return;

        temp.push_back(candidates[index]);
        solve(candidates, target - candidates[index], temp, index);
        temp.pop_back();
        solve(candidates, target, temp, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, temp, 0);
        return result;
    }
};
