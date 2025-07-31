// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

class Solution {
  private:
    void heapify(int ind, vector<int>& arr, int N) {
        if (ind == N) return;
        int max_ind = ind;
        
        int l = 2*ind + 1;
        if (l < N && arr[max_ind] < arr[l]) max_ind = l;
        
        int r = 2*ind + 2;
        if (r < N && arr[max_ind] < arr[r]) max_ind = r;
        
        if (ind != max_ind) {
            swap(arr[ind], arr[max_ind]);
            heapify(max_ind, arr, N);
        }
    }
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for (int i=(N-1)/2; i>=0; i--) {
            heapify(i, arr, N);
        }
    }
};
