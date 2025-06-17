/* Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
The pointer should be initialized to a non-existent number smaller than any element in the BST.
  
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
  
int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.      */


/*
##APPROACH 1:- VECTOR BASED (STORE FULL INORDER)
-STORE THE ENTIRE INORDER TRAVERSAL IN A VECTOR DURING INTIALIZATION.
-USE AN INDEX TO TRACK next() CALLS.

         TIME COMPLEXITY:- O(N) [full inorder traversal at start + O(1) for next() call for N nodes]
         SPACE COMPLEXITY:- O(N) [store all N node values in a vector] 
         
-This approach is simple to implement & gives fast next() & hasNext().
-Avoid this approach if BST is huge due to high space usage.                                              */

//my code-1
class BSTIterator {
    vector<int> inorder;
    int index = 0;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root); // fills the vector at the beginning
    }

    int next() {
        return inorder[index++];
    }

    bool hasNext() {
        return index < inorder.size();
    }
};

/*
##APPROACH 2:- STACK BASED (LAZY INORDER TRAVERSAL)
-Use a stack to simulate the inorder traversal of a BST.
-In the constructor, push all the left nodes starting from the root into the stack.
-next() pops the top node (smallest element) and pushes all the left nodes of its right subtree.
-hasNext() just checks if the stack is non-empty.
-This gives us the next smallest node on each call in O(1) amortized time.

      TIME COMPLEXITY:- O(N)  [O(1) for next() call for N nodes]
      SPACE COMPLEXITY:- O(H) [H-> Height of the tree]                                                      

-Preffered for large BSTs or partial traversal.                                               */

//my code-2
class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

  
      
