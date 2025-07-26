// https://www.naukri.com/code360/problems/check-identical-trees_799364
// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// https://leetcode.com/problems/same-tree/description/
// https://www.youtube.com/watch?v=BhuvF_-PWS0

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
    if (p==NULL || q==NULL) return (p==q);
    
    return (p->data == q->data)
            && identicalTrees(p->left, q->left)
            && identicalTrees(p->right, q->right);
}