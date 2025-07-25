// https://www.naukri.com/code360/problems/preorder-traversal_3838888?interviewProblemRedirection=true&search=preorder
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// https://www.geeksforgeeks.org/problems/preorder-traversal/1
// https://www.youtube.com/watch?v=RlUu72JrOCQ


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
void func(vector<int>& order, TreeNode* root){
        if (root == NULL) return;
        order.emplace_back(root->data);
        func(order, root->left);
        func(order, root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root) {
    if (root == NULL) return {};
    vector<int> order;
    func(order, root);
    return order;
}
