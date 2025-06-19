/* Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101                      */
                       

/*
##APPROACH:-
-For each number i from 0 to n, count how many 1s are present in its binary representation using Brian Kernighan’s algorithm
 (which removes the rightmost set bit in each iteration).
-Store the count in the result array — so at the end, ans[i] contains the number of set bits in binary of i.

   TIME COMPLEXITY:- O(N LOGN)
   SPACE COMPLEXITY:- O(N)                                 */


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<n+1;i++){
            int count=0; int x=i;
            while(x!=0){                //Brian Kernighan’s algorithm
                x=x&(x-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
