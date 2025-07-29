// https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333
// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
// https://www.youtube.com/watch?v=9TJYWh0adfk

// leetcode won't get submitted
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

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int count = 0;
    int result = -1;
    BinaryTreeNode<int>* curr = root;
    
    while (curr != NULL) {
        if (curr->left == NULL) {
            count++;
            if (count == k) {
                result = curr->data;
                break;
            }
            curr = curr->right;
        } else {
            BinaryTreeNode<int>* prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                count++;
                if (count == k) {
                    result = curr->data;
                    break;
                }
                curr = curr->right;
            }
        }
    }
    return result;
}

// if want to clean up any remaining threads
while (root != NULL) {
    if (root->left != NULL) {
        TreeNode* prev = root->left;
        while (prev->right != NULL && prev->right != root) {
            prev = prev->right;
        }
        if (prev->right == root) {
            prev->right = NULL;
        }
    }
    root = root->right;
}
return result;