// https://www.naukri.com/code360/problems/kth-smallest-element_893056
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

int kthSmallest(int n,int k,vector<int> nums) {
    priority_queue<int> max_heap;
    for (int i=0; i<n; i++) {
        if (max_heap.size() != k) max_heap.push(nums[i]);
        else {
            if (nums[i] < max_heap.top()) {
                max_heap.pop();
                max_heap.push(nums[i]);
            }
        }
    }
    return max_heap.top();
}