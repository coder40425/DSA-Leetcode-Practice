/* Given the root of a binary tree, return the preorder traversal of its nodes' values.

 
Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]


#APPROACH:-
-PREORDER TRAVERSAL: ROOT -> LEFT -> RIGHT
-RECURSSIVE APPROACH

        TIME COMPLEXITY:- O(N)    [N-> NO. OF NODES IN BINARY TREE]
        SPACE CPMPLEXITY:- O(H)   //AUXILLIARY STACK SPACE  [H->HEIGHT OF TREE]                                                               */



class Solution {
public:
    void preorder(TreeNode*root, vector<int>&result){
        if(root==nullptr) return;                      //IF TREE IS EMPTY
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        preorder(root,result);
        return result;
        }
};
