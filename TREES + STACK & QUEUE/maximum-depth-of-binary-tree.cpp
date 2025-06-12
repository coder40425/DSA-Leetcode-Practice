/* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
  
Example 2:
Input: root = [1,null,2]
Output: 2


#APPROACH:-
-DFS, RECURSSION
-IF TREE IS EMPTY, DEPTH IS ZERO.
-RECURSSIVELY CALCULATE DEPTH OF LEFT.
-RECURSSIVELY CALCULATE DEPTH OF RIGHT.
-RESULT WILL BE MAX OF LEFT & RIGHT SUBTREE DEPTHS + 1 (FOR CURRENT NODE).

       TIME COMPLEXITY:- O(N)    //N->TOTAL NO. OF NODES
       SPACE COMPLEXITY:- O(H)  //H->HEIGHT OF BINARY TREE                                      */
  

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};
