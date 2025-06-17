/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
   construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
  
Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]                                    */

/*
##APPROACH:
- In preorder traversal, the first element is always the root of the tree.
-  Use a hashmap to store indices of inorder elements for quick lookup.
- Recursively build the tree:
     → Pick current node from preorder using preIndex.
     → Find its position in inorder to divide left and right subtrees.
     → Recur for left and right subtree using inorder boundaries.

   TIME COMPLEXITY   - O(N)
   SPACE COMPLEXITY  - O(N)  // For hashmap and recursion stack
                                                                                                         */

class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        root->left = build(preorder, inorder, inStart, inIndex - 1);
        root->right = build(preorder, inorder, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build a map to get index of value in inorder in O(1)
        for (int i = 0; i < inorder.size(); ++i)
            inorderMap[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
