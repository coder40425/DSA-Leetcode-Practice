/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle values.
For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]      */

/*
##APPROACH:-
-Using two Multi-sets

  TIME COMPLEXITY:- O(n * logk)    SPACE COMPLEXITY:- O(n)       */

//my solution
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // Multisets store window elements in two halves
        multiset<int> left, right;  // left: max half, right: min half
        vector<double> result;

        // Function to balance sizes of left and right multisets
        auto balance = [&]() {
            // Move elements to make right have at most 1 more than left
            while (left.size() > right.size()) {
                right.insert(*left.rbegin());  // move max of left to right
                left.erase(prev(left.end()));  // remove it from left
            }
            while (right.size() > left.size() + 1) {
                left.insert(*right.begin());   // move min of right to left
                right.erase(right.begin());    // remove it from right
            }
        };

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];

            // Add number to appropriate half
            if (right.empty() || num >= *right.begin()) {
                right.insert(num);  // goes to right if large
            } else {
                left.insert(num);   // else to left
            }

            balance();  // always keep both halves balanced

            // If window size exceeded, remove the element out of window
            if (i >= k) {
                int to_remove = nums[i - k];
                if (right.find(to_remove) != right.end()) {
                    right.erase(right.find(to_remove));
                } else {
                    left.erase(left.find(to_remove));
                }
                balance();  // re-balance after removal
            }

            // Once we've added k elements, store the median
            if (i >= k - 1) {
                if (k % 2 == 1) {
                    result.push_back(*right.begin() * 1.0);
                } else {
                    result.push_back(((double)*right.begin() + *left.rbegin()) / 2.0);
                }
            }
        }

        return result;
    }
};
