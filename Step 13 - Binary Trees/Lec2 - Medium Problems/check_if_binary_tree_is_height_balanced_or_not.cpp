// https://www.naukri.com/code360/problems/is-height-balanced-binary-tree_975497
// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
// https://leetcode.com/problems/balanced-binary-tree/description/
// https://www.youtube.com/watch?v=Yt50Jfbd8Po

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int getHeight(TreeNode<int>* root) {
    if (root == NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if (lh == -1 || rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}
bool isBalancedBT(TreeNode<int>* root){
    if (root == NULL) return true;
    if (abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
        isBalancedBT(root->left) &&
        isBalancedBT(root->right)) return true;
    return false;
}

// another sol.
int getHeight(TreeNode<int>* root) {
    if (root == NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if (lh == -1 || rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}
bool isBalancedBT(TreeNode<int>* root){
    if (root == NULL) return true;
    if (getHeight(root) == -1) return false;
    return true;
}
