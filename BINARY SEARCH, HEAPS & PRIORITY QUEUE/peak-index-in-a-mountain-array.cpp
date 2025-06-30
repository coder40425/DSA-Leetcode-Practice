/*You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
 Return the index of the peak element.
 Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

/*
##APPROACH:-
-Using Binary Search
-Initialize low = 0, high = arr.size() - 1
-While low <= high, check for peak element.

     TIME COMPLEXITY:- O(LOG N)         SPACE COMPLEXITY:- O(1)               */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid+1]) return mid;   //found peak index
            if(arr[mid] < arr[mid - 1]) high = mid;  //to check before mid
            else{
                low = mid + 1;  //to check after mid
            }
        }
        return -1;    //will never return -1, as peak element always exists
    }
};
