// https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// https://www.youtube.com/watch?v=vRVfmbCFW7Y

// memoization
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for (int k=i; k<=j-1; k++) {
        int steps = arr[i-1] * arr[k] * arr[j] +
                    f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int> (N, -1));
    return f(1, N-1, arr, dp);
}

// tabulation
#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int> (N, 0));

    for (int i=N-1; i>=1; i--) {
        for (int j=i+1; j<N; j++) {
            int mini = 1e9;
            for (int k=i; k<=j-1; k++) {
                int steps = arr[i-1] * arr[k] * arr[j] +
                            dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}
