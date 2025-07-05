/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]       */

/*
##APPROACH 1:-
-Priority Queue + Sliding Window
-Pair of (value, index) -> Max-Heap.
-Push pair in max heap one by one.
-Remove elements out of current window.
-Add answers in result when window size is valid.

       TIME COMPLEXITY:- O(n * logk)    SPACE COMPLEXITY:- O(k)         */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; //value, index
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
    
         while(!pq.empty() && pq.top().second <= i-k){
             pq.pop();
         }
         if(i >= k-1) result.push_back(pq.top().first);
        }
        return result;
    }
};

/*
##APPROACH 2:-
-Using Deque
-Deque stores the indices of useful elements.
-Remove out of window indices from front.
-Remove all elements from back.
-Push current index at back.
-Start storing results only after window is of size k.

       TIME COMPLEXITY:- O(n)    SPACE COMPLEXITY:- O(k)         */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;

        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
