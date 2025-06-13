/* Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5


#APPROACH:-
-INITIALIZE A QUEUE & PUSH THE ROOT WITH DEPTH 1.
-WHILE THE QUEUE IS NOT EMPTY:
  -POP THE FRONT NODE & ITS DEPTH,
  -IF THE NODE IS A LEAF NODE(NO LEFT & RIGHT CHILD), RETURN CURRENT DEPTH
  -IF LEFT EXISTS, PUSH IT TO THE QUEUE WITH DEPTH + 1
  -IF RIGHT EXISTS, PUSH IT TO THE QUEUE WITH DEPTH + 1

         TIME COMPLEXITY:- O(N)
         SPACE COMPLEXITY:- O(N)                                                   */


class Solution {
public:
    int minDepth(TreeNode* root) {             
        if (!root) return 0;     //EDGE CASE

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If this is a leaf, return depth
                if (!node->left && !node->right) {
                    return depth;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth; // This line will never be reached in a valid tree
    }
};
