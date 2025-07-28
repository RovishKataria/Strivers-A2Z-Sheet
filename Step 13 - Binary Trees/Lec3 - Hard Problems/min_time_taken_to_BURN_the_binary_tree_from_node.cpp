// https://www.naukri.com/code360/problems/time-to-burn-tree_1469067
// https://www.geeksforgeeks.org/problems/burning-tree/1
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/solutions/4539675/python-by-dfs-bfs-w-comment/
// https://www.youtube.com/watch?v=2r5wLmQfD6g

/************************************************************

    Following is the Binary Tree node structure

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
    };

************************************************************/
#include<bits/stdc++.h>
BinaryTreeNode<int>* findTarget(BinaryTreeNode<int>* node, int target) {
    if (!node) return NULL;
    if (node->data == target) return node;
    
    BinaryTreeNode<int>* left = findTarget(node->left, target);
    if (left) return left;
    return findTarget(node->right, target);
}
void markParent(BinaryTreeNode<int>* root,
unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent_track) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();

        if (node->left) {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    BinaryTreeNode<int>* target = findTarget(root, start);

    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_track;
    markParent(root, parent_track);

    int curr_time = 0;
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>*> q;

    q.push(target);
    visited[target] = true;

    while (!q.empty()) {
        int siz = q.size();
        bool didBurn = false;

        for (int i=0; i<siz; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
                didBurn = true;
            }
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
                didBurn = true;
            }
            if (parent_track[node] && !visited[parent_track[node]]) {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
                didBurn = true;
            }
        }
        if (didBurn) curr_time++;
    }
    return curr_time;
}
