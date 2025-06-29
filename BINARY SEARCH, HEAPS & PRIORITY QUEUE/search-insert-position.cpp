/*Given a sorted array of distinct integers and a target value, return the index if the target is found. 
 If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1                                                          */

/*
##APPROACH:- 
-Use Binary Search
-After loop, when the target is not found, return low as the insert position.

    TIME COMPLEXITY:- O(LOG N)         SPACE COMPLEXITY:- O(1)          */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;  //found
            if(nums[mid] < target) low = mid+1;
            else{
                high = mid-1;
            }
        }
        return low;   //insert position
    }
};
