/* Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
  
Example 2:
Input: root = []
Output: []
  
Example 3:
Input: root = [0]
Output: [0]                                      */


/*
##APPROACH 1:- (REVERSE PREORDER + RECURSION)
1. Traverse the tree in reverse preorder: right → left → root.
2. Use a pointer prev to keep track of the previously visited node.
3. Recursively flatten the right subtree first, then the left.
4. For each node:
  -Set node->right = prev (connect to the previously flattened part).
  -Set node->left = nullptr.
  -Update prev = node.

       TIME COMPLEXITY:- O(N) [Visits every node]
       SPACE COMPLEXITY:- O(H) [Recursion Stack]                                   */

//my code 1
class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);        // right subtree
        flatten(root->left);         // left subtree

        root->right = prev;          // connect to previously flattened node
        root->left = nullptr;        // remove left link
        prev = root;                 // update prev
    }
};


/*
##APPROACH 2:- (STACK BASED)
1. Use a stack to simulate recursion (mimic preorder traversal).
2. Start with root. Push root onto the stack.
3. While stack is not  empty:
    -Pop top node → curr.
    -Push curr->right (if exists) → stack
    -Push curr->left (if exists) → stack
    -Modify curr->right to stack.top() (next preorder node)
    -Set curr->left = nullptr

     TIME COMPLEXITY:- O(N) [Visits every node]           
     SPACE COMPLEXITY:- O(H) [Stack stores nodes (Max. H at a time)]                    */

//my code 2
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            if (!st.empty())
                curr->right = st.top();  // next preorder node

            curr->left = nullptr;
        }
    }
};

 
