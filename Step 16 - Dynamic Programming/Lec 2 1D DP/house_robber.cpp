// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
// https://leetcode.com/problems/house-robber/description/
// https://www.naukri.com/code360/problems/loot-houses_630510?leftPanelTabValue=PROBLEM
// https://www.youtube.com/watch?v=GrMBfJNk_NY

// memoization
#include <bits/stdc++.h> 
int f(int ind, vector<int>& nums, vector<int>& dp) {
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    
    int pick = nums[ind] + f(ind-2, nums, dp);
    int nonpick = 0 + f(ind-1, nums, dp);
    
    return dp[ind] = max(pick, nonpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n-1, nums, dp);
}

// tabulation
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    
    for (int i=1; i<n; i++) {
        int pick = nums[i];
        if (i > 1) pick += dp[i-2];
        int nonpick = 0 + dp[i-1];

        dp[i] = max(pick, nonpick);
    }
    return dp[n-1];
}

// optimized
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0], prev2 = 0;
    
    for (int i=1; i<n; i++) {
        int pick = nums[i];
        if (i > 1) pick += prev2;
        int nonpick = 0 + prev;

        int curr = max(pick, nonpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

