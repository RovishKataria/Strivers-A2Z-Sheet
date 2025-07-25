// https://www.naukri.com/code360/problems/inorder-traversal_3839605
// https://www.geeksforgeeks.org/problems/inorder-traversal/1
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// https://www.youtube.com/watch?v=Z_NEgBgbRVI

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
    order.emplace_back(root->data);
    func(order, root->right);
}
vector<int> getInOrderTraversal(TreeNode *root) {
    if (root == NULL) return {};
    vector<int> order;
    func(order, root);
    return order;
}

