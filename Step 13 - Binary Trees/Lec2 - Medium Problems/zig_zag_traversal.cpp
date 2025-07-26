// https://www.naukri.com/code360/problems/binary-tree-zigzag-traversal_1062662
// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// https://www.youtube.com/watch?v=3OXWEdlIGl4

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    vector<int> result;
    if (root == NULL) return result;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool left_to_right = true;
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i=0; i<size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            // Finding position
            int index = (left_to_right) ? i : (size-i-1);

            level[index] = node->data;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        left_to_right = !left_to_right;
        for (int x : level) result.push_back(x);
    }
    return result;
}
