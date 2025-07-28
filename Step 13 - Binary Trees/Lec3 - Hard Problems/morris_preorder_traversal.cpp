// https://www.naukri.com/code360/problems/preorder-traversal_3838888?interviewProblemRedirection=true&search=preorder
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// https://www.geeksforgeeks.org/problems/preorder-traversal/1
// https://www.youtube.com/watch?v=80Zug6D1_r4

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> preorder;
    if (root == NULL) return preorder;
    
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;
            
            if (prev->right == NULL) {
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}