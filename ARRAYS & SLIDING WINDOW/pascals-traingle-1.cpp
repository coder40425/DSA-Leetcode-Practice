/* Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

              1
            1   1
          1   2    1
        1   3    3    1
      1   4    6    4    1
 
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]               


#APPROACH:-
-The code below builds Pascal's Triangle up to 'numRows'.
-Each row starts and ends with 1, and inner elements are calculated using the sum of two elements from the previous row.
-row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j].
-The triangle is stored as a 2D vector and each row is appended iteratively.
-I have mentioned the steps in the code too.
  
              Time complexity: O(n^2)
              Space complexity: O(n^2)                                                         */


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);  // Step 1: initialize row of size (i+1) with all 1s

        // Step 2: Fill middle elements using values from the previous row
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);  // Step 3: Add row to triangle
    }

    return triangle;
}
};
