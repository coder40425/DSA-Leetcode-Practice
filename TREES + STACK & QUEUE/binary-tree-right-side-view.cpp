/* Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]

Example 3:
Input: root = [1,null,3]
Output: [1,3]

Example 4:
Input: root = []
Output: []


#APPROACH (BFS, LEVEL ORDER TRAVERSAL)
-THINK OF STANDING ON THE RIGHT SIDE OF THE TREE AND WATCHING IT LEVEL BY LEVEL.
-AT EVERY LEVEL, THE LAST NODE WE ENCOUNTER WHILE SCANNING LEFT TO RIGHT IS THE ONE THATS VISIBLE FROM THE RIGHT.
-SO, TRAVERSE LEVEL BY LEVEL(FROM LEFT TO RIGHT).
-AT EACH LEVEL. TRACK THE LAST NODE(RIGHTMOST).
-ADD IT TO THE RESULT.

     TIME COMPLEXITY:- O(N)
     SPACE COMPLEXITY:- O(W)  // W-> MAX. WIDTH OF THE TREE                                           */


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front(); q.pop();
            if (i == size - 1) result.push_back(curr->val);  // last node at this level
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    return result;
}
};
