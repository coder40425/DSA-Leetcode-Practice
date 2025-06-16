/* Given the root of a binary tree and an integer targetSum,
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
  
Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
  
Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.


#APPROACH:-(DFS - Depth First Search)
-We want to check if there's a root-to-leaf path such that the sum of node values == targetSum.
-So we go down each path using DFS.
-At each node:
-Subtract its value from the target sum
-If it's a leaf (no children) and remaining sum == 0 → return true
-Else, keep checking left and right paths.

          TIME COMPLEXITY:- O(N)
          SPACE COMPLEXITY:- O(H) (H-> HEIGHT OF THE TREE)                                                   */

//MY CODE
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;            //tree empty
        if(!root->left && !root->right){   //check if it is a leaf node
            return targetSum==root->val;
        }
              //check left & right with reduced target
        return hasPathSum(root->left,targetSum - root->val) ||   
             hasPathSum(root->right,targetSum - root->val);
    }
};
