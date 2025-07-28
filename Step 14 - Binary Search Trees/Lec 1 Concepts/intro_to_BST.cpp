// https://www.geeksforgeeks.org/problems/binary-search-trees/1
// https://www.youtube.com/watch?v=p7-9UvDQZ3w

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        for (int i=0; i<arr.size()-1; i++) {
            if (arr[i] == arr[i+1]) return false;
            if (arr[i] > arr[i+1]) return false;
        }
        return true;
    }
};