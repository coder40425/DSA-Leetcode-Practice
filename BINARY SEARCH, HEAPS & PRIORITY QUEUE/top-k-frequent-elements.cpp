/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
  
Example 2:
Input: nums = [1], k = 1
Output: [1]                   */

/*
##APPROACH:-
-Min-Heap(to keep tract of top k frequent elements) + Hashmap (for frequency counting)
-Min-Heap stores the pair of (frequency, number).
-Lower frequency stays at top.
-If size > k, remove top (element with lowest frequency)
-Extract the top k elements from the heap as the final result.

     TIME COMPLEXITY:- O(n) + O(n logk) + O(k) = O(n logk)       SPACE COMPLEXITY:- O(n) + O(k) + O(k) = O(n)          */

//my solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        for(int num : nums){
            freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto& [num, count] : freq){
            pq.push({count, num});
            if(pq.size() > k) pq.pop();
        }
        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
