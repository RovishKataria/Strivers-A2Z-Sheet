// https://www.naukri.com/code360/problems/minimum-elements_3843091
// https://www.geeksforgeeks.org/problems/number-of-coins1824/1
// https://leetcode.com/problems/coin-change/description/
// https://www.youtube.com/watch?v=mVg9CfJvayM

// video solution for this problem will only work in one case 
// if sum of two coins never exceeds the right coin value just like in real life coins.
// Greedy Solution - Let we have coins/notes like the real world
vector<int> findMin(vector<int>& coins, int n, int V) {
    vector<int> ans;
    for (int i=n-1; i>=0; i--) {
        while (V >= coins[i]) {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}

// but the problems have different denominations so it can only be solved using DP
// DP Solution (Step 16 - Lec 4 - min_coins.cpp)
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