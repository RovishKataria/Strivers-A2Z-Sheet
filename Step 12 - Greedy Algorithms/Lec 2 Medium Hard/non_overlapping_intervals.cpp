// https://www.naukri.com/code360/problems/non-overlapping-intervals_3169341
// https://www.geeksforgeeks.org/problems/non-overlapping-intervals/0
// https://leetcode.com/problems/non-overlapping-intervals/description/
// https://www.youtube.com/watch?v=HDHQ8lAWakY

bool comp(vector<int> val1, vector<int> val2) {
    return (val1[1] < val2[1]);
}
int minimumReschedules(int n, vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    // // lambda function
    // sort(intervals.begin(), intervals.end(),
    //     [](vector<int> val1, vector<int> val2) 
    //         { return (val1[1] < val2[1]); }
    // );
    int cnt = 1, last_end_time = intervals[0][1];
    for (int i=1; i<n; i++) {
        if (intervals[i][0] >= last_end_time) {
            cnt++;
            last_end_time = intervals[i][1];
        }
    }
    return n - cnt;
}
