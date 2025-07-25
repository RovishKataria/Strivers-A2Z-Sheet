// https://www.naukri.com/code360/problems/postorder-traversal_2035933
// https://www.geeksforgeeks.org/problems/postorder-traversal/1
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// https://www.youtube.com/watch?v=NzIGLLwZBS8

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> order;
    if (root == NULL) return order;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            TreeNode* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                order.emplace_back(temp->data);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    order.emplace_back(temp->data);
                }
            }
            else curr = temp;
        }
    }
    return order;
}