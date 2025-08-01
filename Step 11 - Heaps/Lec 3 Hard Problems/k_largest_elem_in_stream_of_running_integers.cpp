// https://www.naukri.com/code360/problems/kth-largest-element-in-a-stream_800301
// https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <algorithm>
class Kthlargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    Kthlargest(int k, vector<int> &arr) {
        this->k = k;
        for (int i=0; i<arr.size(); i++) add(arr[i]);
    }

    int add(int num) {
        if (min_heap.size() < k) min_heap.push(num);
        else if (min_heap.top() < num) {
            min_heap.pop();
            min_heap.push(num);
        }
        return min_heap.top();
    }
};


class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i=0; i<n; i++) {
            min_heap.push(arr[i]);
            if (min_heap.size() < k) {
                ans.push_back(-1);
            } else ans.push_back(min_heap.top());
        }
        return ans;
    }
};