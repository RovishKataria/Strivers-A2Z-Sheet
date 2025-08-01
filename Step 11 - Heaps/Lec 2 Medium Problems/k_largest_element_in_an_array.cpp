// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i=0; i<n; i++) {
            if (min_heap.size() != k) min_heap.push(nums[i]);
            else {
                if (nums[i] > min_heap.top()) {
                    min_heap.pop();
                    min_heap.push(nums[i]);
                }
            }
        }
        return min_heap.top();
    }
};