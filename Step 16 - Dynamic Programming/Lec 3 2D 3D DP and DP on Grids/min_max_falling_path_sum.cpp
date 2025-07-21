// https://www.naukri.com/code360/problems/minimum-falling-path-sum_893012
// https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
// https://leetcode.com/problems/minimum-falling-path-sum/description/
// https://www.youtube.com/watch?v=N_aJ5qQbYA0

// memoization
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>& vec, int n, vector<vector<int>>& dp) {
    if (j < 0 || j >= n) return 1e9;
    if (i == 0) return vec[0][j];
    if (dp[i][j] != -1) return dp[i][j];
    int up_left = vec[i][j] + f(i-1, j-1, vec, n, dp);
    int up = vec[i][j] + f(i-1, j, vec, n, dp);
    int up_right = vec[i][j] + f(i-1, j+1, vec, n, dp);

    return dp[i][j] = min(up_left, min(up, up_right));
}
int minFallingPathSum(vector<vector<int>> &vec, int n) {
    int mini = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j=0; j<n; j++) {
        mini = min(mini, f(n-1, j, vec, n, dp));
    }
    return mini;
}

// tabulation
#include <bits/stdc++.h> 
int minFallingPathSum(vector<vector<int>> &vec, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j=0; j<n; j++) dp[0][j] = vec[0][j];

    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            int up_left = vec[i][j], up = vec[i][j], up_right = vec[i][j];

            if (j-1>=0) up_left += dp[i-1][j-1];
            else up_left += 1e9;
            up += dp[i-1][j];
            if (j+1<n) up_right += dp[i-1][j+1];
            else up_right += 1e9;

            dp[i][j] = min(up_left, min(up, up_right));
        }
    }
    int mini = 1e9;
    for (int j=0; j<n; j++) mini = min(mini, dp[n-1][j]);
    return mini;
}

// optimized
#include <bits/stdc++.h> 
int minFallingPathSum(vector<vector<int>> &vec, int n) {
    vector<int> prev(n, 0);
    for (int j=0; j<n; j++) prev[j] = vec[0][j];

    for (int i=1; i<n; i++) {
        vector<int> curr(n, 0);
        for (int j=0; j<n; j++) {
            int up_left = vec[i][j], up = vec[i][j], up_right = vec[i][j];

            if (j-1>=0) up_left += prev[j-1];
            else up_left += 1e9;
            up += prev[j];
            if (j+1<n) up_right += prev[j+1];
            else up_right += 1e9;

            curr[j] = min(up_left, min(up, up_right));
        }
        prev = curr;
    }
    int mini = 1e9;
    for (int j=0; j<n; j++) mini = min(mini, prev[j]);
    return mini;
}