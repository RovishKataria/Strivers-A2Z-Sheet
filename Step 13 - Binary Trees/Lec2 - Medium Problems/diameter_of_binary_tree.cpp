// https://www.naukri.com/code360/problems/diameter-of-binary-tree_920552
// https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// https://leetcode.com/problems/diameter-of-binary-tree/description/
// https://www.youtube.com/watch?v=Rezetez59Nk

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

// TC = (n)
int findMax(TreeNode<int>* node, int& maxi) {
    if (node == NULL) return 0;
    int lh = findMax(node->left, maxi);
    int rh = findMax(node->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root){
    if (root == NULL) return 0;
    int maxi = 0;
    findMax(root, maxi);
    return maxi;
}
