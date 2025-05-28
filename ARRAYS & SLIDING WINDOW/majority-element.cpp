/* Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2     

APPROACH:
-GIVEN THAT MAJORITY ELEMENT ALWAYS EXISTS WHICH REDUCES OUR NO. OF EDGE CASES.
-SO WE WILL USE HASHMAPS HERE (UNORDERED MAPS) FOR FREQUENCY COUNTING.
-WE WILL TRAVERSE THROUGH THE ARRAY AND WILL INCREASE FREQ. (i.e. FREQ[NUM]++), EVERY TIME A PARTICULAR ELEMENT WILL REPEAT ITSELF. 
  (NUM MEANS NUMS[i] FOR A PARTICULAR INDEX i)
-AFTER FREQUENCY COUNTING, CHECK THE CONDITION IF (FREQ[NUM] > N/2) FOR ANY NUM.
-IF YES, RETURN NUM.  (ALWAYS YES BECAUSE ITS GIVEN, IT WILL ALWAYS EXIST)

   TIME COMPLEXITY- O(N)
   SPACE COMPLEXITY-O(1)  
                                                                                                                       */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;      //using hashmaps (frequency counting)
    int n = nums.size();

    for (int num : nums) {
        freq[num]++;
        if (freq[num] > n / 2)
            return num;
    }

    return -1; // If no majority (not expected in this problem as it is given that majority element always exits
}
};
