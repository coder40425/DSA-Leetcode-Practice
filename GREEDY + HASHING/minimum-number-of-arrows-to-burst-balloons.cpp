/*There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points
where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend.
You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].        */


/*
##APPROACH:-
-Sort balloons by end points.
-Shoot an arrow at the end of the first baloon i.e. at points[0][1]
-For each balloon, if it starts after the current arrow's position, shoot a new arrow.

   TIME COMPLEXITY:- O(N*LOGN)         SPACE COMPLEXITY:- O(1)                      */

//MY SOLUTION
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      //EDGE CASE: NO BALLOONS -> NO ARROWS NEEDED
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
          //SORT BY THEIR ENDING X COORDINATE
            return a[1] < b[1];
        });
        int arrows= 1;
        int arrowEnd= points[0][1];

        for(int i=1;i<points.size();i++){
          // IF THE CURRENT BALLOON STARTS AFTER THE LAST ARROW'S REACH
            if(points[i][0] > arrowEnd){
              //SHOOT A NEW ARROW
                arrows++;
              //UPDATE ARROW POSITION TO THIS BALLOON'S END
                arrowEnd = points[i][1];
            }
          //ELSE, BALLOON IS ALREADY BURST BY THE CURRENT ARROW
        }
        return arrows;
    }
};
