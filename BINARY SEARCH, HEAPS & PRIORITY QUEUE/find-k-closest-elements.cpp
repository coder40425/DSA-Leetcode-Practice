/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
 An integer a is closer to x than an integer b if:
 |a - x| < |b - x|, or
 |a - x| == |b - x| and a < b
 
Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]                              */

/*
##APPROACH:-
-Binary Search + Window (size k)
-Since array is sorted, a window of size k is always continuous.
-When low == high, we have to extract the window of size k from that left/right to left/right + k.

      TIME COMPLEXITY:- O(LOG(N-k)+k)       SPACE COMPLEXITY:O(k)         */

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0, right = arr.size()-k;
        while(left < right){
            int mid = (left + right)/2;
           //compare distance: if left end is farther, move right
            if(x - arr[mid] > arr[mid+k]-x) left = mid+1;
            else{ //move left
                right = mid;
            }
        }
        //extract the window of k elements starting from left
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};

