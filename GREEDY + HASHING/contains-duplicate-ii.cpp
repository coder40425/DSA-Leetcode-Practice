/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true
  
Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true
  
Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false                             */

/*
#APPROACH:-
-Use a hashmap to store the last seen index of each element.
-If the same element appears again within k distance → return true.

     TIME COMPLEXITY:- O(N)
     SPACE COMPLEXITY:- O(N)                           */

//my solution
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //hashmap tp store the last index where each number was seen
        unordered_map<int, int> lastseenIndex;
        for(int i=0;i<nums.size();i++){
            //checks if the number was seen before
            if(lastseenIndex.count(nums[i])){
                //checks if the distance between the indices is <= k
                if(i - lastseenIndex[nums[i]] <= k) 
                        return true;  //duplicate found within allowed range
            }
            lastseenIndex[nums[i]] = i;   //update the last seen index
        }
        return false;
    }
};
