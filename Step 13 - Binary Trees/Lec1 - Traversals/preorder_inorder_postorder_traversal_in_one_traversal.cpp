// https://www.naukri.com/code360/problems/tree-traversal_981269
// https://www.youtube.com/watch?v=ySp2epYvgTE

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
vector<vector<int>> getTreeTraversal(TreeNode *root){
        if (root == NULL) return {};
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        vector<int> preorder, inorder, postorder;
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            if (it.second == 1) {
                preorder.emplace_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2) {
                inorder.emplace_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }
            else {
                postorder.emplace_back(it.first->data);
            }
        }
        vector<vector<int>> result = {inorder, preorder, postorder};
        return result;
}
