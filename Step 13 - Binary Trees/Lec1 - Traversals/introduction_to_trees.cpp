// https://www.geeksforgeeks.org/problems/introduction-to-trees/1
// https://www.youtube.com/watch?v=_ANrF3FJm7I

class Solution {
  public:
    int countNodes(int i) {
        return pow(2, i - 1);
    }
};