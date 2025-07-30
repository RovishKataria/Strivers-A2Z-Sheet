// https://www.naukri.com/code360/problems/maximum-meetings_1062658
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// https://www.youtube.com/watch?v=mKfhTotEguk

#include<bits/stdc++.h>
int maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<vector<int>> meetings;
    // meetings = {id, start_time, end_time};
    for (int i=0; i<n; i++) {
        meetings.push_back({i+1, start[i], end[i]});
    }
    // ascending order sorting on basis of end_time
    sort(meetings.begin(), meetings.end(),
        [](vector<int>&m1, vector<int>&m2) { return m1[2] < m2[2]; }
    );
    
    // initially assign 1st meeting
    int cnt = 1;
    int free_time = meetings[0][2];
    vector<int> selected;
    selected.push_back(meetings[0][0]);
    
    for (int i=1; i<n; i++) {
        if (meetings[i][1] > free_time) {
            cnt++;
            free_time = meetings[i][2];
            selected.push_back(meetings[i][0]);
        }
    }
    return cnt;
}