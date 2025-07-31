// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        for (int i=n-1/2; i>=0; i--) {
            int l = 2*i+1;
            int r = 2*i+2;
            if (l <= n && arr[i] < arr[l]) return false;
            if (r <= n && arr[i] < arr[r]) return false;
        }
        return true;
    }
};