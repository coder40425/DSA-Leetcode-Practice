/* Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
  
Example 2:
Input: root = [1]
Output: [[1]]
  
Example 3:
Input: root = []
Output: []


#APPROACH: (BFS USING QUEUE)
-BASE CASE: IF ROOT == NULL, RETURN AN EMPTY VECTOR.
-INITIALIZE A QUEUE 'Q' TO STORE NODES & A RESULT VECTOR OF VECTORS TO STORE FINAL OUTPUT.
-WHILE QUEUE IS NOT EMPTY
  -GET THE SIZE OF QUEUE.(NO. OF NODES AT CURRENT LEVEL)
  -CREATE A TEMPORARAY VECTOR 'LEVEL' TO HOLD VALUES OF CURRENT LEVEL.
  -LOOP FROM 0 TO SIZE - 1
  -POP THE NODE FROM QUEUE
  -ADD NODE->VAL TO LEVEL
  -PUSH ITS LEFT & RIGHT CHILDREN (IF EXISTS) INTO THE QUEUE
-AFTER LEVEL IS DONE, PUSH 'LEVEL' INTO RESULT.

             TIME COMPLEXITY:- O(N)
             SPACE COMPLEXITY:- O(N)                                                           */
  
//MY CODE
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;     //temporary vector for this level
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front(); 
            q.pop();
            level.push_back(curr->val);      //add node->val to level
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(level);        //add this level to result
    }
    return result;
}  
};
 
