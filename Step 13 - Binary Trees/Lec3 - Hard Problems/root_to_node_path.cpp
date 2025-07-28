// https://www.naukri.com/code360/problems/path-in-a-tree_3843990
// https://www.youtube.com/watch?v=fmflMqVOC7k

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool getPath(TreeNode<int>* node, int x, vector<int>& ans) {
	if (node == NULL) return false;
	ans.push_back(node->data);
	if (node->data == x) return true; 
	
	if (getPath(node->left, x, ans) || getPath(node->right, x, ans))
		return true;
	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x) {
    vector<int> ans;
	if (root == NULL) return ans;
	getPath(root, x, ans);
	return ans;
}
