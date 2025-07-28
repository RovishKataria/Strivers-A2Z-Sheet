// https://www.naukri.com/code360/problems/tree-symmetricity_630426
// https://www.geeksforgeeks.org/problems/symmetric-tree/1
// https://leetcode.com/problems/symmetric-tree/description/
// https://www.youtube.com/watch?v=nKggNAiEpBE

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool isSymmetricHelp(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right) {
    if (left == NULL || right == NULL) return left == right;
    if (left->data != right->data) return false;
    return isSymmetricHelp(left->left, right->right)
        && isSymmetricHelp(left->right, right->left);
}
bool isSymmetric(BinaryTreeNode<int>* root) {
    return (root == NULL) || isSymmetricHelp(root->left, root->right);
}