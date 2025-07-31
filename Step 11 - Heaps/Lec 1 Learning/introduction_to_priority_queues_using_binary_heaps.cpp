// https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1

// User function Template for C++
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].

class Solution {
  public:
    int leftChild(int i) {
        return 2 * i + 1;
    }
    int rightChild(int i) {
        return 2 * i + 2;
    }
    void shiftDown(int i) {
        int max_ind = i;
        int l = leftChild(i);
        if (l <= s && H[l] > H[max_ind]) max_ind = l;
        
        int r = rightChild(i);
        if (r <= s && H[r] > H[max_ind]) max_ind = r;
        
        if (i != max_ind) {
            swap(H[i], H[max_ind]);
            shiftDown(max_ind);
        }
    }
    int extractMax() {
        if (s == -1) return -1;
        int max_elem = H[0];
        H[0] = H[s];
        s--;
        shiftDown(0);
        return max_elem;
    }
};
