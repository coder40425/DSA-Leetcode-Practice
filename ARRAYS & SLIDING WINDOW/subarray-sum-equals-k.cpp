/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2                                 

APPROACH:
 -We will have to find the number of subarrays whose sum is equal to k.
 -We will create outer and inner loops. (i & j)
 -Initialize i from 0 and j from i (for every value of i)
 -For every i, j will go through the array while adding sum (i.e sum = sum + nums[j])
 -Whenever sum becomes equal to k, make count++ (i.e increase the count by 1)
 -Answer will be the final count value (i.e return count)
 
   TIME COMPLEXITY- O(N)
   SPACE COMPLEXITY-O(1)  
                                                                                                                 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
            sum=sum+nums[j];
            if(sum==k){
                count++;
            }
            }
        }
        return count;
    }
};
