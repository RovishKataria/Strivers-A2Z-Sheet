// https://www.naukri.com/code360/problems/unbounded-knapsack_1215029
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// https://www.youtube.com/watch?v=OgvOZ6OrJoY

// memiozation
int f(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    if (ind == 0) return ((int)(W / wt[0])) * val[0];
    if (dp[ind][W] != -1) return dp[ind][W];
    
    int not_take = 0 + f(ind-1, W, val, wt, dp);
    int take = 0;
    if (wt[ind] <= W) take = val[ind] + f(ind, W-wt[ind], val, wt, dp);
    return dp[ind][W] = max(take, not_take);
}
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, val, wt, dp);
}

// tabulation
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for (int W=0; W<=w; W++) dp[0][W] = ((int)(W / wt[0])) * val[0];

    for (int ind=1; ind<n; ind++) {
        for (int W=0; W<=w; W++) {
            int not_take = 0 + dp[ind-1][W];
            int take = 0;
            if (wt[ind] <= W) take = val[ind] + dp[ind][W-wt[ind]];
            dp[ind][W] = max(take, not_take);
        }
    }

    return dp[n-1][w];
}

// optimized
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<int> prev(w+1, 0), curr(w+1, 0);
    for (int W=0; W<=w; W++) prev[W] = ((int)(W / wt[0])) * val[0];

    for (int ind=1; ind<n; ind++) {
        for (int W=0; W<=w; W++) {
            int not_take = 0 + prev[W];
            int take = 0;
            if (wt[ind] <= W) take = val[ind] + curr[W-wt[ind]];
            curr[W] = max(take, not_take);
        }
        prev = curr;
    }

    return prev[w];
}

// optimized to 1 array
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<int> prev(w+1, 0);
    for (int W=0; W<=w; W++) prev[W] = ((int)(W / wt[0])) * val[0];

    for (int ind=1; ind<n; ind++) {
        for (int W=0; W<=w; W++) {
            int not_take = 0 + prev[W];
            int take = 0;
            if (wt[ind] <= W) take = val[ind] + prev[W-wt[ind]];
            prev[W] = max(take, not_take);
        }
    }

    return prev[w];
}