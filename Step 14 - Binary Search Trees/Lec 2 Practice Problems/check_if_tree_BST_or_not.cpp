// https://www.naukri.com/code360/problems/validate-bst_981275
// https://www.geeksforgeeks.org/problems/check-for-bst/1
// https://leetcode.com/problems/validate-binary-search-tree/description/
// https://www.youtube.com/watch?v=f-sj7I5oXEI

#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
bool checkValid(BinaryTreeNode<int>* node, long long min_val, long long max_val) {
    if (node == NULL) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return checkValid(node->left, min_val, node->data) &&
            checkValid(node->right, node->data, max_val);
}
bool validateBST(BinaryTreeNode<int>* root) {
    return checkValid(root, LLONG_MIN, LLONG_MAX);
}