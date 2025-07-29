// https://www.naukri.com/code360/problems/lca-in-a-bst_981280
// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// https://www.youtube.com/watch?v=cX_kPV_foZc

/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL) return NULL;
    if (p->data < root->data && q->data < root->data)
        return LCAinaBST(root->left, p, q);
    if (p->data > root->data && q->data > root->data)
        return LCAinaBST(root->right, p, q);
    return root;
}