/* Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]


#APPROACH:-
-INORDER TRAVERSAL: LEFT -> ROOT -> RIGHT 
-RECURSSIVE APPROACH

        TIME COMPLEXITY:- O(N)    [N-> NO. OF NODES IN BINARY TREE]
        SPACE CPMPLEXITY:- O(H)   //AUXILLIARY STACK SPACE  [H->HEIGHT OF TREE]                                                               */


class Solution {
public:
    void inorder(TreeNode*root, vector<int>&result){
        if(root==nullptr) return;                        //IF TREE IS EMPTY
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        inorder(root,result);
        return result;
        }
};





 












