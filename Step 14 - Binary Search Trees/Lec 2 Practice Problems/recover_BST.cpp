// https://www.naukri.com/code360/problems/fix-bst_873137
// https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
// https://leetcode.com/problems/recover-binary-search-tree/description/
// https://www.youtube.com/watch?v=ZWGW7FminDM

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
TreeNode* first;
TreeNode* prev_node;
TreeNode* middle;
TreeNode* last;

void inorder(TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    if (prev_node != NULL && root->data < prev_node->data) {
        // if first violation
        if (first == NULL) {
            first = prev_node;
            middle = root;
        } 
        // if second violation
        else last = root;
    }
    prev_node = root;
    inorder(root->right);
}
TreeNode * FixBST(TreeNode * root){
    first = middle = last = NULL;
    prev_node = new TreeNode(INT_MIN);
    inorder(root);
    if (first && last) swap(first->data, last->data);
    else if (first && middle) swap(first->data, middle->data);
    return root;
}