/* Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0  */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int max_seen = nums[0];
        int min_seen = nums[n - 1];

        // Right boundary
        for (int i = 1; i < n; i++) {
            if (nums[i] < max_seen) {
                right = i;
            } else {
                max_seen = nums[i];
            }
        }

        // Left boundary
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > min_seen) {
                left = i;
            } else {
                min_seen = nums[i];
            }
        }

        return (right == -1) ? 0 : (right - left + 1);
    }
};

/* Approach:

Use 3 pointers: low, mid, and high.

Iterate and swap elements based on their value (0, 1, 2).

Push 0s to front, 2s to end, 1s stay in the middle.

Runs in one pass with O(1) space. */
