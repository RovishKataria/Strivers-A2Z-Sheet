// https://www.naukri.com/code360/problems/maximum-sum-path-of-a-binary-tree_1214968
// https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
// https://www.youtube.com/watch?v=WszrfSwMz58

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getSum(BinaryTreeNode<int>* node, int& max_sum) {
    if (node == NULL) return 0;
    int ls = max(0, getSum(node->left, max_sum));
    int rs = max(0, getSum(node->right, max_sum));
    max_sum = max(max_sum, node->data + ls + rs);
    return node->data + max(ls, rs);
}
int maxPathSum(BinaryTreeNode<int> *root) {
    if (root == NULL) return 0;
    int max_sum = INT_MIN;
    getSum(root, max_sum);
    return max_sum;
}
