// https://www.naukri.com/code360/problems/inorder-traversal_3839605
// https://www.geeksforgeeks.org/problems/inorder-traversal/1
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// https://www.youtube.com/watch?v=lxTGsVXjwvM

vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> order;
    if (root == NULL) return order;
    stack<TreeNode*> st;
    TreeNode *node = root;
    
    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if (st.empty()) break;
            node = st.top();
            st.pop();
            order.emplace_back(node->data);
            node = node->right;
        }
    }
    return order;
}