// https://www.naukri.com/code360/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539
// https://www.geeksforgeeks.org/problems/construct-tree-1/1
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// https://www.youtube.com/watch?v=aZNaLrVebKQ

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* constructTree(vector<int>& preorder, int pre_start, int pre_end,
    vector<int>& inorder, int in_start, int in_end, map<int, int>& in_map) {
    if (pre_start > pre_end || in_start > in_end) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(preorder[pre_start]);
    int in_root = in_map[root->data];
    int nums_left = in_root - in_start;
    root->left = constructTree(preorder, pre_start+1, pre_start+nums_left,
                                inorder, in_start, in_root-1, in_map);
    root->right = constructTree(preorder, pre_start+nums_left+1, pre_end,
                                inorder, in_root+1, in_end, in_map);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
    map<int, int> in_map;
    for (int i=0; i<inorder.size(); i++) in_map[inorder[i]] = i;

    TreeNode<int>* root = constructTree(preorder, 0 ,preorder.size()-1,
                                    inorder, 0, inorder.size()-1, in_map);
    return root;
}