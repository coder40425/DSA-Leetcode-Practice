/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]                                         */

class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor) {
        int m = image.size();
        int n = image[0].size();

        // Base case: out of bounds or not matching original color
        if(i < 0 || j < 0 || i >= m || j >= n || image[i][j] != color) return;

        image[i][j] = newColor;  // Color current pixel

        // Move in 4 directions
        dfs(image, i+1, j, color, newColor);
        dfs(image, i-1, j, color, newColor);
        dfs(image, i, j+1, color, newColor);
        dfs(image, i, j-1, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor) // avoid infinite recursion
            dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};
