/*You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.               */

/*
##APPROACH:-
-Using Binary Search
-Initialize low = 1, high = n
-While low < high, check for bad version.
-Will stop at low == high, that is our first bad version.

     TIME COMPLEXITY:- O(LOG N)         SPACE COMPLEXITY:- O(1)               */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1, high=n;

        while(low < high){
            int mid = low + (high - low)/2;     //to avoid overflow
            if(isBadVersion(mid)) high = mid;   //mid might be the first bad version or before it
            else{
                low = mid + 1;     //mid is good, so first bad must be after mid
            } 
        }
        return low;
    }
};
