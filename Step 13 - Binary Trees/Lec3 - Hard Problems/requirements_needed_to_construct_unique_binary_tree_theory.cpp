// https://www.naukri.com/code360/problems/unique-binary-tree_8180906
// https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1
// https://www.youtube.com/watch?v=9GMECGQgWrQ

int uniqueBinaryTree(int a, int b){
    return (a == 2 && (b == 1 || b == 3)) ||
           (b == 2 && (a == 1 || a == 3));
}