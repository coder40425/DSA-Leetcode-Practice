/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].     */

/*
##APPROACH:-
-Max-Heap (to store the ({distance from origin, points[i]})).
-Since its origin distance (i.e., √(x1 - x2)2 + (y1 - y2)2) becomes distance (i.e., √(x1)2 + (y1)2)
-For comparison we can just use sum of squares & neglect root for ease of calculations.
-If size > k, remove top (element with highest distance)
-Extract the top k elements from the heap as the final result.

     TIME COMPLEXITY:- O(n logk)       SPACE COMPLEXITY:- O(k)        */

//my solution
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;
        for(int i=0;i<points.size();i++){
            int x= points[i][0], y=points[i][1];
            int distance = x*x + y*y;
            pq.push({distance, points[i]});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>>result;
         while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
