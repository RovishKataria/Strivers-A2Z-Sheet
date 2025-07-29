// https://www.naukri.com/code360/problems/pair-sum_4444818
// https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
// https://www.youtube.com/watch?v=ssL3sHwPeb4

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
class BSTiterator {
private:
    stack<TreeNode<int>*> st;
    // reverse = true -> before
    // reverse = false -> next
    bool reverse = true;

    void pushAll(TreeNode<int>* node) {
        while (node != NULL) {
            st.push(node);
            if (!reverse) node = node->left;
            else node = node->right;
        }
    }
public:
    BSTiterator(TreeNode<int>* root, bool is_rev) {
        reverse = is_rev;
        pushAll(root);
    }
    int next() {
        TreeNode<int>* node = st.top();
        st.pop();
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }
    bool hasNext() {
        return !st.empty();
    }
};
bool kSumPair(TreeNode < int > * root, int k) {
   if (root == NULL) return false;
   // left -> next
   BSTiterator l(root, false);
   // right -> before
   BSTiterator r(root, true);

   int i = l.next();
   int j = r.next();
   while (i < j) {
       if (i + j == k) return true;
       else if (i + j < k) i = l.next();
       else j = r.next();
   }
   return false;
}
