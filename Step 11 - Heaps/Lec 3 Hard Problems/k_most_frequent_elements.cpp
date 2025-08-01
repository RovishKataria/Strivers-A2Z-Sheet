// https://www.naukri.com/code360/problems/k-most-frequent-elements_3167808
// https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
// https://leetcode.com/problems/top-k-frequent-elements/

#include<bits/stdc++.h>
typedef pair<int, int> pii;
vector<int> KMostFrequent(int n, int k, vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pii, vector<pii>, greater<pii>> min_heap;

    for (auto& [num, count] : freq) {
        min_heap.push({count, num});
        if (min_heap.size() > k)
            min_heap.pop();
    }

    vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }
    return result;
}