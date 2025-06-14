/* Given the root of a binary tree, invert the tree, and return its root.


Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
  
Example 2:
Input: root = [2,1,3]
Output: [2,3,1]
  
Example 3:
Input: root = []
Output: []


#APPROACH:- ITERATIVE LEVEL ORDER TRAVERSAL USING QUEUE
-CHECK IF THE ROOT IS NULL. IF YES, RETURN NULL IMMEDIATELY.
-INITIALIZE A QUEUE AND PUSH THE ROOT NODE INTO IT.
-WHILE THE QUEUE IS NOT EMPTY, POP THE FRONT NODE.
-SWAP ITS LEFT AND RIGHT CHILD NODES.
-IF LEFT OR RIGHT CHILD EXISTS, PUSH THEM INTO THE QUEUE.
-REPEAT UNTIL ALL NODES ARE PROCESSED. RETURN THE MODIFIED ROOT.
  
      TIME COMPLEXITY:- O(N)
      SPACE COMPLEXITY:- O(N)    WHERE N IS THE NUMBER OF NODES IN THE TREE.                  */


                                      
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode*node= q.front();
            q.pop();
            
            TreeNode*temp=node->left;
            node->left=node->right;
            node->right=temp;


            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        return root;
    }
};
