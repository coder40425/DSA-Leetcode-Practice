/* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3
  
Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99                              */


/*
#APPROACH:-
-We iterate through all 32 bit positions (0 to 31).
-For each bit, we count how many numbers have that bit set.
-If the count is not divisible by 3, it means the unique number has that bit set.
-We build the result by setting such bits using bitwise OR.

        TIME COMPLEXITY: O(32 * N) → O(N) (We scan all bits for all N elements)
        SPACE COMPLEXITY: O(1) (Only integer variables are used)                            */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // Traverse all 32 bits of an integer
        for (int i = 0; i < 32; ++i) {
            int sum = 0;

            // Count number of elements with the i-th bit set
            for (int num : nums) {
                if ((num >> i) & 1)
                    sum++;
            }

            // If sum % 3 != 0, that bit is set in the unique number
            if (sum % 3 != 0)
                result |= (1 << i);  // Set the i-th bit in result
        }

        return result;
    }
};
