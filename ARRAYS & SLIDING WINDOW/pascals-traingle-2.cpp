/*  Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

               1        
            1   1
          1   2    1
        1   3    3    1
      1   4   6    4    1

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1] */

// Returns the k-th row of Pascal’s Triangle using O(k) space.
// Starts with row[0] = 1 and builds each row in-place from right to left.
// Updates follow Pascal's rule: row[j] += row[j - 1].
// Reverse loop ensures previous values aren't overwritten during calculation.
// Time: O(k^2), Space: O(k)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 0);
    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            row[j] += row[j - 1];
        }
    }
    return row;
}
};
