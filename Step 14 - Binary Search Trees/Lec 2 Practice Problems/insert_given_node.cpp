// https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913
// https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// https://www.youtube.com/watch?v=FiFiNvM29ps

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


************************************************************/

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val) {
    if (root == NULL) return new TreeNode<int>(val);
    TreeNode<int>* curr = root;
    while (true) {
        if (val < curr->val) {
            if (curr->left != NULL) curr = curr->left;
            else {
                curr->left = new TreeNode<int>(val);
                break;
            }
        }
        else {
            if (curr->right != NULL) curr = curr->right;
            else {
                curr->right = new TreeNode<int>(val);
                break;
            }
        }
    }
    return root;
}