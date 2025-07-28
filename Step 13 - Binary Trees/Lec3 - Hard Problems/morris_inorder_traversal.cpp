// https://www.naukri.com/code360/problems/inorder-traversal_3839605
// https://www.geeksforgeeks.org/problems/inorder-traversal/1
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// https://www.youtube.com/watch?v=80Zug6D1_r4

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
vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> inorder;
    if (root == NULL) return inorder;
    
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;
            
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}