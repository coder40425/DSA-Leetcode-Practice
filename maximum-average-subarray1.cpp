class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSum = 0;
         // sliding window approach- O(N)
        // Step 1: Calculate initial window sum
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];     
        }

        int maxSum = windowSum;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};
