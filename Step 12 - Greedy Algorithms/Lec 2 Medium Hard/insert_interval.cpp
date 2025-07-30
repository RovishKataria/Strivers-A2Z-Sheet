// https://www.naukri.com/code360/problems/insert-interval_1102297
// https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1
// https://leetcode.com/problems/insert-interval/description/
// https://www.youtube.com/watch?v=xxRE-46OCC8

#include <bits/stdc++.h> 
vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;
    // left
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }
    // check overlap
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res.push_back(newInterval);
    // right
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}