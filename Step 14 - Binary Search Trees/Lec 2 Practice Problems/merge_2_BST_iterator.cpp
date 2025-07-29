// https://www.naukri.com/code360/problems/bst-iterator_1112601

// https://leetcode.com/problems/binary-search-tree-iterator/description/
// https://www.youtube.com/watch?v=D2jMcmxU4bs

#include <bits/stdc++.h> 
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

class BSTiterator {
private:
    stack<TreeNode<int>*> st;

    void pushAll(TreeNode<int>* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTiterator(TreeNode<int> *root) {
        pushAll(root);
    }

    int next() {
        TreeNode<int>* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }

    bool hasNext() {
        return !st.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/