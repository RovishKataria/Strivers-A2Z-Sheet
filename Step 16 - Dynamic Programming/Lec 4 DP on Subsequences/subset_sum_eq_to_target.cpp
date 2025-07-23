// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// https://leetcode.com/problems/target-sum/description/
// https://www.youtube.com/watch?v=fWX9xDmIzRI

// memoization
#include <bits/stdc++.h> 
int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == 0) return (arr[0] == target);
    if (dp[ind][target] != -1) return dp[ind][target];

    bool not_take = f(ind-1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) take = f(ind-1, target - arr[ind], arr, dp);
    
    return dp[ind][target] = take | not_take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}

// tabulation
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for (int i=0; i<n; i++) dp[i][0] = true;
    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int ind=1; ind<n; ind++) {
        for (int target=1; target<=k; target++) {
            bool not_take = dp[ind-1][target];
            bool take = false;
            if (arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
            
            dp[ind][target] = take | not_take;
        }
    }
    return dp[n-1][k];
}

// optimized
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int ind=1; ind<n; ind++) {
        for (int target=1; target<=k; target++) {
            bool not_take = prev[target];
            bool take = false;
            if (arr[ind] <= target) take = prev[target-arr[ind]];
            
            curr[target] = take | not_take;
        }
        prev = curr;
    }
    return prev[k];
}