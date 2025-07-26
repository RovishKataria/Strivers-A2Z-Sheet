// https://www.naukri.com/code360/problems/right-view_764605
// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// https://leetcode.com/problems/binary-tree-right-side-view/description/
// https://www.youtube.com/watch?v=KV4mRzTjlAk

/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

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
void f(BinaryTreeNode<int>* node, int level, vector<int>& ans) {
    if (node == NULL) return;
    if (level == ans.size()) ans.push_back(node->data);
    f(node->right, level+1, ans);
    f(node->left, level+1, ans);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    f(root, 0, ans);
    return ans;
}

// https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// For left view just swap last 2 function calls