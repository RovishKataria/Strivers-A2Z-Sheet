// https://www.naukri.com/code360/problems/count-complete-binary-tree-nodes_982774
// https://www.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1
// https://leetcode.com/problems/count-complete-tree-nodes/description/
// https://www.youtube.com/watch?v=u-yWemKGWO0

#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
int findLH(TreeNode<int>* node) {
    if (node == NULL) return 0;
    int h = 0;
    while (node) {
        h++;
        node = node->left;
    }
    return h;
}
int findRH(TreeNode<int>* node) {
    if (node == NULL) return 0;
    int h = 0;
    while (node) {
        h++;
        node = node->right;
    }
    return h;
}
int countNodes(TreeNode<int> *root) {
    if (root == NULL) return 0;
    int lH = findLH(root);
    int rH = findRH(root);
    if (lH == rH) return (1<<lH) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}