// https://www.naukri.com/code360/problems/postorder-traversal_2035933
// https://www.geeksforgeeks.org/problems/postorder-traversal/1
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// https://www.youtube.com/watch?v=COQOU6klsBg

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void func(vector<int>& order, TreeNode* root) {
    if (root == NULL) return;
    func(order, root->left);
    func(order, root->right);
    order.emplace_back(root->data);
}
vector<int> postorderTraversal(TreeNode *root) {
    if (root == NULL) return {};
    vector<int> order;
    func(order, root);
    return order;
}

