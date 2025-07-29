// https://www.naukri.com/code360/problems/floor-from-bst_625868
// https://www.geeksforgeeks.org/problems/floor-in-bst/1
// https://www.youtube.com/watch?v=xm_W1ub-K-w

int Floor(BinaryTreeNode<int> *node, int input)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	int floor = -1;
	while (node) {
		if (node->data == input) return node->data;
		else if (node->data < input) {
			floor = node->data;
			node = node->right;
		}
		else node = node->left;
	}
	return floor;
}
