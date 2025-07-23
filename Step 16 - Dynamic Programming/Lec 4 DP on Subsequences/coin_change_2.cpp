// https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471?leftPanelTabValue=PROBLEM
// https://www.geeksforgeeks.org/problems/coin-change2448/1
// https://leetcode.com/problems/coin-change-ii/description/
// https://www.youtube.com/watch?v=HgyouUi11zk

// memoization
#include<bits/stdc++.h>
long f(int ind, int T, int *a, vector<vector<long>>& dp) {
    if (ind == 0) return (T % a[0] == 0);
    if (dp[ind][T] != -1) return dp[ind][T];

    long not_take = f(ind-1, T, a, dp);
    long take = 0;
    if (a[ind] <= T) take = f(ind, T-a[ind], a, dp);

    return dp[ind][T] = take + not_take;
}
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long> (value+1, -1));
    return f(n-1, value, denominations, dp);
}

// tabulation
#include<bits/stdc++.h>
long countWaysToMakeChange(int *a, int n, int value) {
    vector<vector<long>> dp(n, vector<long> (value+1, 0));
    for (int T=0; T<=value; T++) dp[0][T] = (T % a[0] == 0);

    for (int ind = 1; ind<n; ind++) {
        for (int T=0; T<=value; T++) {
            long not_take = dp[ind-1][T];
            long take = 0;
            if (a[ind] <= T) take = dp[ind][T-a[ind]];

            dp[ind][T] = take + not_take;
        }
    }
    return dp[n-1][value];
}

// optimized
#include<bits/stdc++.h>
long countWaysToMakeChange(int *a, int n, int value) {
    vector<long> prev(value+1, 0), curr(value+1, 0);
    for (int T=0; T<=value; T++) prev[T] = (T % a[0] == 0);

    for (int ind = 1; ind<n; ind++) {
        for (int T=0; T<=value; T++) {
            long not_take = prev[T];
            long take = 0;
            if (a[ind] <= T) take = curr[T-a[ind]];

            curr[T] = take + not_take;
        }
        prev = curr;
    }
    return prev[value];
}