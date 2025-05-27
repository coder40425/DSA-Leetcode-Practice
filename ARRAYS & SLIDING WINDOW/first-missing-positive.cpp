/* Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 
Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.          */

/* APPROACH-
  (Index Marking Trick)
-Place them in the correct/ideal position. (ideal position: +ve integer x should be at x-1  e.g 3 should be at index 2)
-If nums[i] is not at the correct index (i.e. nums[i]-1 != nums[i]), swap with the element at its correct index.
-As we have to find the smallest missing positive integer, so we will not consider neagtive integers and zero.
-Therefore check the bounds (i.e. 0<nums[i]<=n) before swapping.
-After correcting their indexes, find first index where the no. is incorrect, answer will be that index + 1.
-If all positions are correct, return n+1.

Time complexity- O(n)
Space complexity- O(1)      */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Place each number in its correct index position
    for (int i = 0; i < n; ++i) {
        while (
            nums[i] > 0 && nums[i] <= n &&
            nums[nums[i] - 1] != nums[i]
        ) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first index where the number is incorrect
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // All positions are correct, return n + 1
    return n + 1;
}
};
