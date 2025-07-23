// https://www.naukri.com/code360/problems/minimum-elements_3843091
// https://www.geeksforgeeks.org/problems/number-of-coins1824/1
// https://leetcode.com/problems/coin-change/description/
// https://www.youtube.com/watch?v=myPeWb3Y68A

// memiozation
#include <bits/stdc++.h> 
int f(int ind, int T, vector<int>& a, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (T % a[0] == 0) return T/a[0];
        return 1e9;
    }
    if (dp[ind][T] != -1) return dp[ind][T];

    int not_take = 0 + f(ind-1, T, a, dp);
    int take = INT_MAX;
    if (a[ind] <= T) take = 1 + f(ind, T - a[ind], a, dp);

    return dp[ind][T] =  min(take, not_take);
}
int minimumElements(vector<int> &num, int target) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    int ans = f(n-1, target, num, dp);
    if (ans >= 1e9) return -1;
    return ans;
}

// tabulation
#include <bits/stdc++.h> 
int minimumElements(vector<int> &a, int target) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
    for (int T=0; T<=target; T++) {
        if (T % a[0] == 0) dp[0][T] = T/a[0];
        else dp[0][T] = 1e9;
    }

    for (int ind=1; ind<n; ind++) {
        for (int T=0; T<=target; T++) {
            int not_take = 0 + dp[ind-1][T];
            int take = INT_MAX;
            if (a[ind] <= T) take = 1 + dp[ind][T-a[ind]];

            dp[ind][T] =  min(take, not_take);
        }
    }
    int ans = dp[n-1][target];
    if (ans >= 1e9) return -1;
    return ans;
}

// optimized
#include <bits/stdc++.h> 
int minimumElements(vector<int> &a, int target) {
    int n = a.size();
    vector<int> prev(target+1, 0), curr(target+1, 0);
    for (int T=0; T<=target; T++) {
        if (T % a[0] == 0) prev[T] = T/a[0];
        else prev[T] = 1e9;
    }

    for (int ind=1; ind<n; ind++) {
        for (int T=0; T<=target; T++) {
            int not_take = 0 + prev[T];
            int take = INT_MAX;
            if (a[ind] <= T) take = 1 + curr[T-a[ind]];

            curr[T] =  min(take, not_take);
        }
        prev = curr;
    }
    int ans = prev[target];
    if (ans >= 1e9) return -1;
    return ans;
}