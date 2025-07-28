// https://www.naukri.com/code360/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106
// https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// https://www.youtube.com/watch?v=LgLRTaEMRVc

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* constructTree(vector<int>& inorder, int in_start, int in_end,
    vector<int>& postorder, int post_start, int post_end, map<int, int>& mpp) {
    if (in_start > in_end || post_start > post_end) return NULL;

    TreeNode<int>* root = new TreeNode<int>(postorder[post_end]);
    int in_root = mpp[root->data];
    int nums_left = in_root - in_start;

    root->left = constructTree(inorder, in_start, in_root-1,
                postorder, post_start, post_start+nums_left-1, mpp);
    root->right = constructTree(inorder, in_root+1, in_end,
                postorder, post_start+nums_left, post_end-1, mpp);
    return root;
    }
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder){
     if (inorder.size() != postorder.size()) return NULL;
     map<int, int> mpp;
     for (int i=0; i<inorder.size(); i++) mpp[inorder[i]] = i;
     
     TreeNode<int>* root = constructTree(inorder, 0, inorder.size()-1,
                         postorder, 0, postorder.size()-1, mpp);
     return root;
}
