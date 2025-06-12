/* Given the root of a binary tree, return the postorder traversal of its nodes' values.

 
Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]


#APPROACH:-
-POSTORDER TRAVERSAL: LEFT -> RIGHT -> ROOT 
-RECURSSIVE APPROACH

        TIME COMPLEXITY:- O(N)    [N-> NO. OF NODES IN BINARY TREE]
        SPACE CPMPLEXITY:- O(H)   //AUXILLIARY STACK SPACE  [H->HEIGHT OF TREE]                                                               */

  
class Solution {
public:
    void postorder(TreeNode*root, vector<int>&result){
        if(root==nullptr) return;                          //IF TREE IS EMPTY
        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root){       //TRAVERSAL
        vector<int>result;                                   
        postorder(root,result);
        return result;
        }
};
