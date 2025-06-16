/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 
Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
  
Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.


#APPROACH:-
-DO POST-ORDER TRAVERSAL (LEFT, RIGHT, ROOT).
-AT EACH NODE, IGNORE NEGATIVE PATHS USING MAX(0, ...).
-UPDATE GLOBAL MAXIMUM WITH LEFT + RIGHT + NODE->VAL (FULL PATH THROUGH NODE).
-RETURN NODE->VAL + MAX(LEFT, RIGHT) TO USE IN PARENT’S PATH.

            TIME: O(N) → VISIT EACH NODE ONCE.
            SPACE: O(H) → HEIGHT OF TREE (RECURSION STACK).                                                             */

//MY CODE
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;  // GLOBAL MAX TO STORE FINAL ANSWER
        maxPathDown(root, maxi);  // START DFS
        return maxi;
    }

    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;  // BASE CASE

        // RECURSIVELY GET LEFT & RIGHT MAX PATH SUMS, IGNORING NEGATIVES
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        // UPDATE GLOBAL MAX IF CURRENT PATH (LEFT + RIGHT + ROOT) IS GREATER
        maxi = max(maxi, left + right + node->val);

        // RETURN MAX ONE-SIDE PATH TO PARENT (CANNOT FORK UPWARD)
        return max(left, right) + node->val;
    }
};
