// https://www.naukri.com/code360/problems/serialize-and-deserialize-binary-tree_920328
// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
// https://www.youtube.com/watch?v=-YbXySKJsX8

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

string serializeTree(TreeNode<int> *root) {
    if (root == NULL) return "";
    string str = "";
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        if (node == NULL) str.append("null,");
        else {
            str.append(to_string(node->data) + ",");
            q.push(node->left);
            q.push(node->right);
        }
    }
    return str;
}

TreeNode<int>* deserializeTree(string &serialized) {
    if (serialized.size() == 0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');

    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        
        getline(s, str, ',');
        if (str == "null") node->left = NULL;
        else {
            node->left = new TreeNode<int>(stoi(str));
            q.push(node->left);
        }

        getline(s, str, ',');
        if (str == "null") node->right = NULL;
        else {
            node->right = new TreeNode<int>(stoi(str));
            q.push(node->right);
        }
    }
    return root;
}



