/* You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
            The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
  
Example 2:
Input: root = []
Output: []                                 */


/*
##APPROACH: (Perfect Binary Tree)
1. Use a pointer leftMost to track the first node of each level (starting from root).
2. For each level, use another pointer head to move across the level using .next pointers.
3. Connect head->left->next = head->right.
4. If head->next exists, connect head->right->next = head->next->left.
5. After completing one level, move leftMost = leftMost->left to proceed to the next level.

   TIME COMPLEXITY:  O(N)   // Every node is visited once
   SPACE COMPLEXITY: O(1)   // No extra space used (constant pointers only)                     */

//my code
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Start with the leftmost node of the current level (initially root)
        Node* leftMost = root;

        // Continue level by level until the leaf level is reached
        while (leftMost->left) {
            Node* head = leftMost;

            // Traverse the current level using next pointers
            while (head) {
                // Connect left child to right child
                head->left->next = head->right;

                // If next node exists, connect right child to next node's left child
                if (head->next) {
                    head->right->next = head->next->left;
                }

                // Move to the next node in the current level
                head = head->next;
            }

            // Move to the next level down
            leftMost = leftMost->left;
        }

        return root;
    }
};
