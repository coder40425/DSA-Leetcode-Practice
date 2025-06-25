/*You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2                           */


/*
#APPROACH:-
-farthest: The farthest index we can reach so far from the current range.
-curEnd: The end of the current jump range.
-Every time i == curEnd, it means we must jump, 
   -increment jumps
   -update curEnd to farthest to prepare for the next segment.

#TIME COMPLEXITY: O(N)   SPACE COMPLEXITY: O(1)       */

//MY SOLUTION
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            // if we reached the end of the current jump range
            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }
        
        return jumps;
    }
};
