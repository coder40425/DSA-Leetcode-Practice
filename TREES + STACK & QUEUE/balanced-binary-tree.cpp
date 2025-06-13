/* Given a binary tree, determine if it is height-balanced.

 
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true
 

#APPROACH:-
-RECURSION, HELPER FUNCTION, POST ORDER TRAVERSAL
(INSTEAD OF CALCULATING THE HEIGHT AND BALANCE SEPARATELY, WE COMBINE BOTH INTO ONE RECURSIVE FUNCTION)
-WE USE A POST ORDER TRAVERSAL AND RETURN:
  -THE HEIGHT IF SUBTREE IS BALANCED.
  -(-1) IF ITS UNBALANCED
-RECURSIVELY GET HEIGHT OF LEFT & RIGHT SUBTREE.
  -IF EITHER RETURNS -1, PROPOGATE -1 (UNBALANCED)
  -IF DIFFERENCE OF HEIGHTS > 1, RETURN -1
  -ELSE RETURN 1+ MAX(LEFTHEIGHT, RIGHTHEIGHT) i.e. THE HEIGHT OF TREE.

         TIME COMPLEXITY:- O(N)
         SPACE COMPLEXITY:- O(N)                                                   */



class Solution {
public:
    // Helper function that returns -1 if unbalanced, else returns height
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1; // Left subtree not balanced

        int right = checkHeight(root->right);
        if (right == -1) return -1; // Right subtree not balanced

        if (abs(left - right) > 1) return -1; // Current node not balanced

        return max(left, right) + 1;    //returns height
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
