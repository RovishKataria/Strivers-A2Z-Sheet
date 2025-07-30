// https://www.geeksforgeeks.org/problems/shortest-job-first/1
// https://www.youtube.com/watch?v=3-QbX1iDbXs

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        int t = 0, wt_time = 0;
        for (int i=0; i<n ; i++) {
            wt_time += t;
            t += bt[i];
        }
        return wt_time/n;
    }
};