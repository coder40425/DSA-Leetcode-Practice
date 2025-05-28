/* Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.                               

APPROACH-
  -We will add one by one to the sum (from i=0 to i<n)
  -sum = sum + nums[i]
    maxsum = max(maxsum,sum)
  -If at any point (sum < 0) means it will not contribute to the maximum subarray, 
  -So we will make sum = 0 again and move forward in the loop.
  -In the end, answer will be the maxsum.
  
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)                                         */

  
class Solution {
public:
  
  int maxsum=INT_MIN;     //INT_MIN is the smallest possible value an integer datatype can hold. (used for the first pass)
  int sum=0;
    int maxSubArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
                sum=sum+nums[i];
                maxsum=max(sum,maxsum);

                if(sum<0){
                    sum=0;
                }   
        }
        return maxsum;
    }
};
