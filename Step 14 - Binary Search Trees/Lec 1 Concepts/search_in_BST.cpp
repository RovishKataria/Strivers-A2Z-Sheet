// https://www.naukri.com/code360/problems/search-in-bst_1402878
// https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1
// https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// https://www.youtube.com/watch?v=KcNt6v_56cc

/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while (root != NULL && root->data != x) {
        root = x < root->data ? root->left : root->right;
    }
    return root;
}