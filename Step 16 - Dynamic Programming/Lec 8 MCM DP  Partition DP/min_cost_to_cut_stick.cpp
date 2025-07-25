// https://www.naukri.com/code360/problems/cost-to-cut-a-chocolate_3208460
// https://www.youtube.com/watch?v=xwomavsC86c

// memoization
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for (int ind=i; ind<=j; ind++) {
        int cost = cuts[j+1] - cuts[i-1] + 
                f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(), 0);
    cuts.emplace_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
    return f(1, c, cuts, dp);
}

// tabulation
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for (int ind=i; ind<=j; ind++) {
        int cost = cuts[j+1] - cuts[i-1] + 
                f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(), 0);
    cuts.emplace_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

    for (int i=c; i>=1; i--) {
        for (int j=1; j<=c; j++) {
            if (i > j) continue;
            int mini = 1e9;
            for (int ind=i; ind<=j; ind++) {
                int cost = cuts[j+1] - cuts[i-1] + 
                        dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
