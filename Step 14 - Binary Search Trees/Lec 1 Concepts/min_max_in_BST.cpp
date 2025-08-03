// https://www.naukri.com/code360/problems/minimum-element-in-bst_8160462
// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */
int minVal(Node* root){
	if (root == NULL) return -1;
	Node* node = root;
	while (node->left != NULL) node = node->left;
	return node->data;	
}