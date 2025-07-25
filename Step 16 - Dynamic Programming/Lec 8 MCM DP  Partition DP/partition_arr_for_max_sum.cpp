// https://www.naukri.com/code360/problems/partition-array-for-maximum-sum_3755255
// https://www.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1
// https://leetcode.com/problems/partition-array-for-maximum-sum/description/
// https://www.youtube.com/watch?v=PhWWJmaKfMc

// memoization
#include<bits/stdc++.h>
int f(int ind, vector<int> &arr, int k, int n, vector<int> &dp) {
    if (ind == n) return 0;
    if (dp[ind] != -1) return dp[ind];

    int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
    for (int j=ind; j<min(n, ind+k); j++) {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + f(j+1, arr, k ,n, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}
int maximumSubarray(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(0, arr, k, n, dp);
}

// tabulation
#include<bits/stdc++.h>
int maximumSubarray(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp(n+1, 0);

    for (int ind=n-1; ind>=0; ind--) {
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        for (int j=ind; j<min(n, ind+k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}