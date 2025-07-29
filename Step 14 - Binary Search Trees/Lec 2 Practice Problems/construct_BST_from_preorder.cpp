// https://www.naukri.com/code360/problems/construct-bst-from-preorder-traversal_2689307
// https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// https://www.youtube.com/watch?v=UmJT3j26t1I

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
TreeNode* build(vector<int> &preOrder, int& ind, int n, int up_bound) {
    if (ind == n || preOrder[ind] > up_bound) return NULL;
    TreeNode* root = new TreeNode(preOrder[ind]);
    ind++;
    root->left = build(preOrder, ind, n, root->data);
    root->right = build(preOrder, ind, n, up_bound);
    return root;
}
TreeNode *preOrderTree(vector<int> &preOrder) {
    if (preOrder.size() == 0) return NULL;
    int ind = 0;
    return build(preOrder, ind, preOrder.size(), INT_MAX);
}