// https://www.naukri.com/code360/problems/sliding-window-maximum_980226
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// https://leetcode.com/problems/sliding-window-maximum/description/
// https://www.youtube.com/watch?v=NwBvene4Imo

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq; // Stores indices

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove all elements smaller than current from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // The window starts forming at i >= k-1
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}