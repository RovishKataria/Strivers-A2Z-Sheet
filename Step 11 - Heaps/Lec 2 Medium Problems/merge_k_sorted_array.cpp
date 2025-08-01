// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Node{
  public:
    int data, row, col;
    Node(int val, int i, int j) {
        data = val;
        row = i;
        col = j;
    } 
};
// Custom comparator for min-heap
struct compare {
    bool operator()(Node* val1, Node* val2) {
        return val1->data > val2->data;  // Min-heap
    }
};
class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        priority_queue<Node*, vector<Node*>, compare> min_heap;
        for (int i=0; i<k; i++) {
            Node* temp = new Node(arr[i][0], i, 0);
            min_heap.push(temp);
        }
        
        vector<int> ans;
        while (!min_heap.empty()) {
            Node* temp = min_heap.top();
            min_heap.pop();
            ans.push_back(temp->data);
            
            int i = temp->row;
            int j = temp->col;
            
            if (j+1 < arr[i].size()) {
                Node* next = new Node(arr[i][j + 1], i, j + 1);
                min_heap.push(next);
            }
        }
        return ans;
    }
};