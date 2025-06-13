/* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
  
Example 2:
Input: root = [1,null,2]
Output: 2


#APPROACH-1:-
-DFS, RECURSSION
-IF TREE IS EMPTY, DEPTH IS ZERO.
-RECURSSIVELY CALCULATE DEPTH OF LEFT.
-RECURSSIVELY CALCULATE DEPTH OF RIGHT.
-RESULT WILL BE MAX OF LEFT & RIGHT SUBTREE DEPTHS + 1 (FOR CURRENT NODE).

       TIME COMPLEXITY:- O(N)    //N->TOTAL NO. OF NODES
       SPACE COMPLEXITY:- O(H)  //H->HEIGHT OF BINARY TREE                                      */

  
//CODE FOR APPROACH 1
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


/* 
#APPROACH-2:-
-BFS, LEVEL ORDER TRAVERSAL (WITHOUT  RECURSSION).
-CREATE A QUEUE 'Q' OF TYPE TREENODE* & INITIALIZE DEPTH = 0, PUSH ROOT IN THE QUEUE.
-WHILE Q IS NOT EMPTY,
  -FOR EACH NODE IN THIS LEVEL,
     POP THE FRONT NODE FROM THE QUEUE
     IF IT HAS A LEFT CHILD, PUSH IT INTO QUEUE
     IF IT HAS A RIGHT CHILD, PUSH IT INTO QUEUE
  -AFTER FINISHING THE CURRENT LEVEL, INCREMENT DEPTH BY 1.
-RETURN THE FINAL VALUE OF DEPTH.

       TIME COMPLEXITY:- O(N)
       SPACE COMPLEXITY:- O(W)  //W IS MAXIMUM WIDTH OF THE TREE                     */


//CODE FOR APPROACH 2
class Solution {
public:
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        depth++;
    }

    return depth;
}
};
  
  
