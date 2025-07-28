// https://www.naukri.com/code360/problems/flatten-binary-tree-to-linked-list_10728332
// https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
// https://www.youtube.com/watch?v=sWf7k1x9XR4

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* prevNode = NULL;
void flattenBinaryTree(TreeNode<int>* root) {
    if (root == NULL) return;
    flattenBinaryTree(root->right);
    flattenBinaryTree(root->left);
    root->right = prevNode;
    root->left = NULL;
    prevNode = root;
}

#include<bits/stdc++.h>
void flattenBinaryTree(TreeNode<int>* root) {
    if (root == NULL) return;
    stack<TreeNode<int>*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode<int>* curr = st.top();
        st.pop();
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
        if (!st.empty()) curr->right = st.top();
        curr->left = NULL;
    }
}

void flattenBinaryTree(TreeNode<int>* root) {
    TreeNode<int>* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            TreeNode<int>* prev = curr->left;
            while (prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}