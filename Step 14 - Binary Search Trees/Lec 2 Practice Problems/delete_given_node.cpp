// https://www.naukri.com/code360/problems/delete-node-in-bst_920381
// https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1
// https://leetcode.com/problems/delete-node-in-a-bst/description/
// https://www.youtube.com/watch?v=kouxiP_H5WE

/*************************************************************
    Following is the Binary Tree node structure

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

*************************************************************/
BinaryTreeNode<int>* findLastRight(BinaryTreeNode<int>* node) {
    if (node->right == NULL) return node;
    return findLastRight(node->right);
}
BinaryTreeNode<int>* helper(BinaryTreeNode<int>* node) {
    if (node->left == NULL) return node->right;
    else if (node->right == NULL) return node->left;
    BinaryTreeNode<int>* right_child = node->right;
    BinaryTreeNode<int>* last_right = findLastRight(node->left);
    last_right->right = right_child;
    return node->left;
}
BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return helper(root);
    
    BinaryTreeNode<int>* node = root;
    while (node != NULL) {
        if (node->data > key) {
            if (node->left != NULL && node->left->data == key) {
                node->left = helper(node->left);
                break;
            }
            else node = node->left;
        }
        else {
            if (node->right != NULL && node->right->data == key) {
                node->right = helper(node->right);
                break;
            }
            else node = node->right;
        }
    }
    return root;
}
