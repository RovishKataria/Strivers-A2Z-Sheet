// https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// https://leetcode.com/problems/boundary-of-binary-tree/description/
// https://www.youtube.com/watch?v=0ca1nvR0be4

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* node) {
    if (node->left == NULL && node->right == NULL) return true;
    return false;
}
void addLeftBoundary(TreeNode<int>* node, vector<int>& res) {
    TreeNode<int>* curr = node->left;
    while (curr) {
        if (!isLeaf(curr)) res.push_back(curr->data);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void addLeaves(TreeNode<int>* node, vector<int>& res) {
    if (isLeaf(node)) {
        res.push_back(node->data);
        return;
    }
    if (node->left) addLeaves(node->left, res);
    if (node->right) addLeaves(node->right, res);
}
void addRightBoundary(TreeNode<int>* node, vector<int>& res) {
    TreeNode<int>* curr = node->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr)) temp.push_back(curr->data);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i=temp.size()-1; i>=0; i--) res.push_back(temp[i]);
}
vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> res;
	if (root == NULL) return res;
    if (!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}
