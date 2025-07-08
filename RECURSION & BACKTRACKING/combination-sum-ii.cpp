/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates 
 where the candidate numbers sum to target.
 Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]                       */

/*
##APPROACH:-
-Using Recursion & Backtracking
-At each level, as we move forward, update target (i.e. target = target - candidates[i])
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
        if(target < 0 || index >= candidates.size()) return;

        for(int i = index;i<candidates.size();i++){
            //skip duplicates at same level
            if(i > index && candidates[i] == candidates[i-1]) continue;
            //early stopping
            if(candidates[i] > target) continue;

          temp.push_back(candidates[i]);
          solve(candidates, target-candidates[i], temp, i+1);

          temp.pop_back();
    }
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, target, temp, 0);
        return result;
    }
};
