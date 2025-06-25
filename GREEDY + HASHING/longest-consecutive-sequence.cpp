/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9                                     */

/*
##APPROACH:-
-USING UNORDERED SET.
-TRAVERSE THE SET, CHECK FOR THE SMALLEST NUMBER FOR A SEQUENCE.
-STORE THE SIZE OF THE LONGEST CONSECUTIVE SEQUENCE.

    TIME COMPLEXITY:- O(N)    SPACE COMPLEXITY:- O(1)              */

//MY SOLUTION
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Put all elements in an unordered_set
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        //traverse the set
        for (int num : s) {
            // Check if it's the start of a new sequence
            if (s.find(num - 1) == s.end()) {
                // This is the smallest number of a new consecutive sequence
                int currentNum = num;
                int streak = 1;

                // Count how long the consecutive streak goes
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    streak++;
                }

                //Update the max streak
                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
