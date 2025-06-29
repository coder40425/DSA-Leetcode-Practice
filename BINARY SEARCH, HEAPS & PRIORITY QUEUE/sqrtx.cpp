/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
 You must not use any built-in exponent function or operator.
 For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.      */

/*
##APPROACH:- 
-Search in range: 0 to x
-Check mid * mid:
  -If mid * mid == x, return mid
  -If mid * mid < x, store mid as a potential answer and move low = mid + 1
  -Else, do high = mid - 1
-Final answer = last mid such that mid*mid <= x

    TIME COMPLEXITY:- O(LOG X)         SPACE COMPLEXITY:- O(1)          */

class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int result;

        while(low <= high){
            long long mid = (low + high)/2;
            long long square = mid*mid;
            if(square == x) return mid;
            if(square < x){
            result = mid;
            low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return result;
    }
};
