/* Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]        */


/*  BRUTE FORCE APPROACH- 

     Works good for small size inputs.
     Run time error(may be) for large inputs.
     Time complexity- O(nlogn)
     space complexity- O(1)  (in place sorting)    */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Step 1: Square each element
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Step 2: Sort the squared array
        sort(nums.begin(), nums.end());

        return nums;
    }
};

/* OPTIMAL SOLUTION

  Works for both small and large inputs.
  Time complexity- O(n)
  Space complexity- O(n)  (extra space i.e result is created)          */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int index = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[index--] = nums[left] * nums[left];
                left++;
            } else {
                result[index--] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};
 
