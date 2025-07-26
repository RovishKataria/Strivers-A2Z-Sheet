// https://www.naukri.com/code360/problems/vertical-order-traversal_920533
// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// https://www.youtube.com/watch?v=q_a6lpbKJdw

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

vector<int> verticalOrderTraversal(TreeNode<int> *root) {
    vector<int> order;
    if (root == NULL) return order;
    

    // map<int, map<int, multiset<int>>> mpp;
    map<int, map<int, vector<int>>> mpp;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int vert = it.second.first;
        int lev = it.second.second;
        
        mpp[vert][lev].push_back(node->data);
        
        if (node->left) q.push({node->left, {vert-1, lev+1}});
        if (node->right) q.push({node->right, {vert+1, lev+1}});
    }

    for (auto it1 : mpp) {
        for (auto it2 : it1.second) {
            for (auto it3 : it2.second) {
                order.push_back(it3);
            }
        }
    }
    return order;
}