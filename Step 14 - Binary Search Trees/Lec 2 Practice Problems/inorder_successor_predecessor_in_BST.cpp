// https://www.naukri.com/code360/problems/predecessor-and-successor-in-bst_893049
// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
// https://leetcode.com/problems/inorder-successor-in-bst/description/
// https://www.youtube.com/watch?v=SXKAD2svfmI

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
TreeNode* inorderPredecessor(TreeNode *root, int key) {
    TreeNode* pre = NULL;
    while (root != NULL) {
        if (root->data < key) {
            pre = root;
            root = root->right;
        } else root = root->left;
    }
    return pre;
}
TreeNode* inorderSuccessor(TreeNode *root, int key) {
    TreeNode* succ = NULL;
    while (root != NULL) {
        if (root->data > key) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    TreeNode* pre_node = inorderPredecessor(root, key);
    TreeNode* succ_node = inorderSuccessor(root, key);
    int pre = -1;
    int succ = -1;
    if (pre_node != NULL) pre = pre_node->data;
    if (succ_node != NULL) succ = succ_node->data;
    return {pre, succ};
}