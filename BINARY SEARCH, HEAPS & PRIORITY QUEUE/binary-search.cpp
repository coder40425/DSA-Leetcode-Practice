/* Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
 If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4           */

/*
##APPROACH:-
-Initialize: low = 0, high = n - 1
-Loop: While low ≤ high, calculate mid = low + (high - low) / 2
-Check:
  -If arr[mid] == target → return mid
  -If arr[mid] < target → search right: low = mid + 1
  -Else → search left: high = mid - 1

     TIME COMPLEXITY:- O(LOG N)         SPACE COMPLEXITY:- O(1)          */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) low = mid+1;
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
