/* Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
  Each path should be returned as a list of the node values, not node references.

  A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

  
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
  
Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []
  
Example 3:
Input: root = [1,2], targetSum = 0
Output: []


##APPROACH:-DFS (DEPTH-FIRST SEARCH) + BACKTRACKING
-INITIALIZE AN EMPTY LIST RESULT TO STORE VALID PATHS.
-DEFINE A RECURSIVE DFS FUNCTION WITH: CURRENT NODE, CURRENT PATH (LIST), REMAINING SUM (TARGETSUM - PATH SUM SO FAR).
-IN THE DFS: IF NODE IS NULLPTR, RETURN. 
-ADD CURRENT NODE TO PATH. 
-IF IT’S A LEAF AND REMAINING SUM EQUALS NODE VALUE → ADD THE PATH TO RESULT. 
-RECURSE INTO LEFT AND RIGHT SUBTREES WITH UPDATED REMAINING SUM.
-BACKTRACK: REMOVE THE LAST NODE FROM PATH.
-RETURN RESULT.

  #TIME COMPLEXITY: O(N * H)       #WORST:- O(N^2)
    Let N be the number of nodes, and H the height of the tree. In the worst case, you visit every node → O(N)
    At each leaf, you may create a copy of the path (which could be up to height H) → O(H) per path

  #SPACE COMPLEXITY: O(M * H)      #WORST:- O(N^2)
    Recursion Stack: Max depth = height → O(H). Path vector: Also up to height → O(H)
    Result: In worst case, you may have many paths, each up to H long → O(M * H) where M is number of valid paths                 */


//MY CODE
class Solution {
public:
    vector<vector<int>> result; // stores all valid paths

    void dfs(TreeNode* node, int targetSum, vector<int>& path) {
        if (!node) return;

        path.push_back(node->val);  // Add current node to path
        targetSum -= node->val;     // Reduce target by node's value

        // If we're at a leaf and targetSum is 0, this path is valid
        if (!node->left && !node->right && targetSum == 0) {
            result.push_back(path); // Save a copy of the path
        }

        // Continue DFS traversal
        dfs(node->left, targetSum, path);
        dfs(node->right, targetSum, path);

        path.pop_back(); //  Backtrack: remove the last node before returning
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path; // track the current path
        dfs(root, targetSum, path);
        return result;
    }
};
