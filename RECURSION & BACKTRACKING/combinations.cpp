/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.       */

/*
##APPROACH:-
-Using Backtracking
-Use recursion to explore all number combinations.
-Use a temporary list & build one path.
-When size reaches k, push to final answer.
-Backtrack by removing last added.

      TIME COMPLEXITY:- O(C(n, k)*k) -> Since there are C(n, k) combinations, each of size k.
      SPACE COMPLEXITY:- O(k)  ->for recursion stack + answer space.                                   */

//my solution
class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int start, int n, int k, vector<int>& temp){
        //base case
        if(temp.size() == k){
        result.push_back(temp);
        } 
        //explore from start to n
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            backtrack(i+1, n, k, temp);
            temp.pop_back();    //backtrack
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        backtrack(1, n, k, temp);
        return result;
    }
};
