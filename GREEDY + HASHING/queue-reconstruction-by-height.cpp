/*You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order).
Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, 
where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

Example 1:
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]                  */


/*
##APPROACH:-
-Sort by height descending (taller people first)
-If two people have same height, sort by k (ascending)
-Insert them one by one.
-Start with an empty list & insert each person at the index = k.

  TIME COMPLEXITY:- O(NLOGN + N^2) = O(N^2)           SPACE COMPLEXITY:- O(N^2)                 */
  
//MY SOLUTION
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](vector<int>&a, vector<int>&b){
          //same height -> sort by k (ascending)
            if(a[0] == b[0]) return a[1] < b[1];
          //else, taller people first
            return a[0] > b[0];
        });
        vector<vector<int>>result;
      //insert each person at index = k in result
        for(auto&person : people){
            result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};
