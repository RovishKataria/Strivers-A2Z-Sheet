// https://www.naukri.com/code360/problems/postorder-traversal_2035933
// https://www.geeksforgeeks.org/problems/postorder-traversal/1
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// https://www.youtube.com/watch?v=2YBhNLodD8Q

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> order;
    if (root == NULL) return order;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL) st1.push(root->left);
        if (root->right != NULL) st1.push(root->right);
    }
    while (!st2.empty()) {
        root = st2.top();
        st2.pop();
        order.emplace_back(root->data);
    }
    return order;
}