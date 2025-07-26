// https://www.naukri.com/code360/problems/maximum-depth-of-a-binary-tree_1090542
// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// https://www.youtube.com/watch?v=eD3tmO66aBA

#include <bits/stdc++.h> 
//TreeNode class definition
/*
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
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

*/

int findMaxDepth(TreeNode<int> *root) {
    if (root == NULL) return 0;
    int lh = findMaxDepth(root->left);
    int rh = findMaxDepth(root->right);
    return 1 + max(lh, rh);
}
