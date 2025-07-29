// https://www.naukri.com/code360/problems/size-of-largest-bst-in-binary-tree_893103
// https://www.geeksforgeeks.org/problems/largest-bst/1
// https://leetcode.com/problems/largest-bst-subtree/description/
// https://www.youtube.com/watch?v=X0oXMdtUDwo

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
class NodeValue {
public:
    int min_node, max_node, max_size;
    NodeValue(int min_node, int max_node, int max_size) {
        this->min_node = min_node;
        this->max_node = max_node;
        this->max_size = max_size;
    }
};
NodeValue helper(TreeNode* root) {
    if (root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);
    
    // left and right subtree
    auto left = helper(root->left);
    auto right = helper(root->right);
    
    // if (left < root < right) then it is BST
    if (left.max_node < root->data && root->data < right.min_node)
        return NodeValue(min(left.min_node, root->data),
                            max(root->data, right.max_node),
                            left.max_size + right.max_size + 1);
    // else return -inf, inf, max_size(left, right);
    return NodeValue(INT_MIN, INT_MAX, max(left.max_size, right.max_size));
}
int largestBST(TreeNode * root){
    return helper(root).max_size;
}