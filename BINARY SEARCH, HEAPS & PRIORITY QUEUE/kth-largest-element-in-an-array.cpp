/*Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
  
Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4                                       */

/*
##APPROACH:-
-Using Min-Heap.
-Push elements into the heap.
-Maintain a min-heap of size k.
-If size > k, pop the topmost element.
-After loop, return the top element of heap.

      TIME COMPLEXITY:- O(n log k)     SPACE COMPLEXITY:- O(k)              */

//MY SOLUTION
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>q;
        for(int num : nums){
            q.push(num);
            if(q.size() > k){
                q.pop();
            }
        }
        return q.top();
    }
};
