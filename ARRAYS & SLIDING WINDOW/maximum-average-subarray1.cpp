/*  You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
Any answer with a calculation error less than 10-5 will be accepted.

 
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000                                              


APPROACH:
-WE WILL USE THE SLIDING WINDOW APPROACH HHERE
  [IT BBASICALLY MEANS, KEEPING A WINDOW OF 'K' ELEMENTS AND WHEN YOU MOVE FORWARD, JUST SUBTRACT THE LEFTMOST ELEMENT OF THE SUBARRAY AND ADD THE NEW RIGHTMOST ELEMENT.]
  [SUPPOSE, WE HAVE A ARRAY OF SIZE 6 (AS SHOWN IN EXAMPLE 1), K = 4, NOW ADD THE FIRST 4 ELEMENTS]
  [TO MOVE FORWARD, SUBTRACT THE FIRST ELEMENT AND ADD THE FIFTH ELEMENT (NOW THE SUM WILL BE OF THE NEXT 4 ELEMENTS AFTER THE FIRST INDEX)]
  [SIMILARLY, AGAIN SLIDE THE WINDOW BY SUBTRACTING SECOND ELEMENT AND ADDING SIXTH ELEMENT AND SO ON !]

-CALCULATE INITIAL WINDOW SUM (i.e. CALCULATE THE SUM OF FIRST 'K' INTEGERS)
-INITIALISE MAX SUM AND MAKE ( MAXSUM = WINDOW SUM)
-NOW SLIDE THE WINDOW AND STORE THE MAXIMUM VALUE,
-RETURN (DOUBLE) MAXSUM/K   (AS MAXIMUM AVERAGE SUM = TOTALSUM / SIZE OF ARRAY)
    


   TIME COMPLEXITY- O(N)
   SPACE COMPLEXITY-O(1)  
                                                                                             */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSum = 0;
        // Step 1: Calculate initial window sum
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];     
        }

        int maxSum = windowSum;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            windowSum = windowSum - nums[i - k] + nums[i];    // NUMS[i-k] WILL BE THE FIRST ELEMENT OF EVERY SUBARRAY OF SIZE K
            maxSum = max(maxSum, windowSum);                   // & NUMS[i] IS THE NEXT ELEMENT AFTER THE SUBARRAY
        }

        return (double)maxSum / k;
    }
};
