/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.      */


/*
##APPROACH:-
-TWO PASS GREEDY (for both increasing and decreasing slopes)

     TIME COMPLEXITY:- O(N)         SPACE COMPLEXITY:- O(N0         */

//MY SOLUTION
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candies(n, 1);   //give everyone 1 candy
      //left to right pass
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
      //right to left pass
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
      //sum all candies
        int sum=0;
        for(int val: candies){
            sum+=val;
        }
        return sum;
    }
};
