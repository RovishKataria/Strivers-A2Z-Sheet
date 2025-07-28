// https://www.naukri.com/code360/problems/print-nodes-at-distance-k-from-a-given-node_842560
// https://www.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// https://www.youtube.com/watch?v=i9ORlEy6EsI

/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
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

*************************************************************/
void markParents(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent_track) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if (node->left) {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int k) {
    vector<BinaryTreeNode<int>*> ans;
    if (root == NULL) return ans;

    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_track; // node -> parent
    markParents(root, parent_track);

    int curr_level = 0;
    queue<BinaryTreeNode<int>*> q;
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    
    q.push(target);
    visited[target] = true;

    while (!q.empty()) {
        int siz = q.size();
        if (curr_level == k) break;
        curr_level++;
        
        for (int i=0; i<siz; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parent_track[node] && !visited[parent_track[node]]) {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        ans.push_back(node);
    }
    return ans;
}