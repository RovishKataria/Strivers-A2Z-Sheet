// https://www.naukri.com/code360/problems/preorder-traversal_3838888?interviewProblemRedirection=true&search=preorder
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// https://www.geeksforgeeks.org/problems/preorder-traversal/1
// https://www.youtube.com/watch?v=Bfqd8BsPVuw

#include <bits/stdc++.h> 
vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> order;
    if (root == NULL) return order;
    
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();
        order.emplace_back(root->data);
        if (root->right != NULL) st.push(root->right);
        if (root->left != NULL) st.push(root->left);
    }
    return order;
}