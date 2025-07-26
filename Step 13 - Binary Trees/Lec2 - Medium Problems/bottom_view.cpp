// https://www.naukri.com/code360/problems/bottom-view-of-binary-tree_893110
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// https://www.youtube.com/watch?v=0FtVY6I4pB8

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root) {
    vector<int> ans;
    if (root == NULL) return ans;
    map<int, int> mpp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int vert = it.second;

        mpp[vert] = node->data;
        if (node->left) q.push({node->left, vert-1});
        if (node->right) q.push({node->right, vert+1});
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}
