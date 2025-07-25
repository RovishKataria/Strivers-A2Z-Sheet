// https://www.naukri.com/code360/problems/level-order-traversal_796002?interviewProblemRedirection=true&search=level
// https://www.geeksforgeeks.org/problems/level-order-traversal/1
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// https://www.youtube.com/watch?v=EoAsWbO7sqg

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size=q.size();
            vector<int> level;
            for (int i=0; i<size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                level.emplace_back(node->val);
            }
            res.emplace_back(level);
        }
        return res;
    }
};

// codestudio
#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root) {
    vector<int> res;
    if (root == NULL) return res;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        res.push_back(node->val);
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
    return res;
}