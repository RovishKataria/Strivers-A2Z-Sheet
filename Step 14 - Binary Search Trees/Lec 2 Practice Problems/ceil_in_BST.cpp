// https://www.naukri.com/code360/problems/ceil-from-bst_920464
// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// https://www.youtube.com/watch?v=KSsk8AhdOZA

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1;
    while (node) {
        if (node->data == x) return node->data;
        else if (node->data > x) {
            ceil = node->data;
            node = node->left;
        }
        else node = node->right;
    }
    return ceil;
}