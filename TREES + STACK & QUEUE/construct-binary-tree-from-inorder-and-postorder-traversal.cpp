/* Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
   construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
  
Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]                                   */


/*
##APPROACH:-
-In postorder, the last element is the current root.
-Use a hashmap to store the index of each element in inorder[] for O(1) lookup.
-Start from the last element in postorder and move backward.
-Recursively build the right subtree first, then the left (because postorder is Left → Right → Root).
-Maintain a global or reference index postIndex to track the root node position in postorder.

         TIME COMPLEXITY:- O(N)
         SPACE COMPLEXITY:- O(N)  [for map & recursion stack]                                          */


class Solution {
public:
    unordered_map<int, int> inorderMap;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];
        //recurse first on right subtree (since we are going backward in postorder, so we will build the right subtree first then the left one.
        root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex); 
        root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Build a map to get index of value in inorder in O(1)
        for (int i = 0; i < inorder.size(); ++i){
            inorderMap[inorder[i]] = i;
        }
        int postIndex= postorder.size()-1;
            
        return build(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};
