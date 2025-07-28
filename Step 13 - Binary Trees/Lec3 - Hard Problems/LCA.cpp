// https://www.naukri.com/code360/problems/lca-of-binary-tree_920541
// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// https://www.youtube.com/watch?v=_-QHfMDde90

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
TreeNode<int>* lca(TreeNode<int> *root, int x, int y) {
	if (root == NULL || root->data == x || root->data == y) return root;
    TreeNode<int>* left = lca(root->left, x, y);
    TreeNode<int>* right = lca(root->right, x, y);

    if (left == NULL) return right;
    else if (right == NULL) return left;
    else return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
    TreeNode<int>* node = lca(root, x, y);
    return node->data;
}