/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
  
Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
  

#APPROACH:- RECURSIVE CHECK FOR MIRROR SUBTREES
-A TREE IS SYMMETRIC IF ITS LEFT AND RIGHT SUBTREES ARE MIRROR IMAGES OF EACH OTHER.
-CALL A HELPER FUNCTION isMirror WITH THE LEFT AND RIGHT SUBTREES OF THE ROOT.
-IN isMirror, IF BOTH NODES ARE NULL, RETURN TRUE.
-IF ONLY ONE IS NULL, RETURN FALSE.
-CHECK IF CURRENT NODE VALUES ARE EQUAL AND RECURSIVELY VERIFY t1->left WITH t2->right AND t1->right WITH t2->left.
-RETURN TRUE ONLY IF ALL CORRESPONDING PAIRS MATCH.

       TIME COMPLEXITY:- O(N)
       SPACE COMPLEXITY:- O(H)   [WHERE N IS THE NUMBER OF NODES, AND H IS THE HEIGHT OF THE TREE (DUE TO RECURSION STACK)]                 */
            
//my code
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode*t1, TreeNode*t2){
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;

        return (t1->val==t2->val) && isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
    }
};


/*
#APPROACH:- ITERATIVE CHECK USING QUEUE FOR PAIRWISE COMPARISON
INITIALIZE A QUEUE AND PUSH THE LEFT AND RIGHT SUBTREES OF THE ROOT.
WHILE THE QUEUE IS NOT EMPTY, POP TWO NODES AT A TIME (t1 AND t2).
IF BOTH ARE NULL, CONTINUE TO NEXT ITERATION.
IF ONE IS NULL OR THEIR VALUES DIFFER, RETURN FALSE.
PUSH CHILDREN IN MIRRORED ORDER: t1->left & t2->right, THEN t1->right & t2->left.
CONTINUE UNTIL THE QUEUE IS EMPTY. IF NO MISMATCH FOUND, RETURN TRUE.
  
     TIME COMPLEXITY:- O(N)
    SPACE COMPLEXITY:- O(N)     [WHERE N IS THE TOTAL NUMBER OF NODES IN THE TREE]                                 */
 
//my code
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            
            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val) return false;
            
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

                                  





 
