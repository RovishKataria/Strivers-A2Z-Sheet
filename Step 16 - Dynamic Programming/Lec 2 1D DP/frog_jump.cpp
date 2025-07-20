// https://www.youtube.com/watch?v=EgG3jsGoPvQ
// https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=SUBMISSION

// memiozation
#include <bits/stdc++.h> 
int f(int ind, vector<int>& heights, vector<int>& dp) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    
    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if (ind > 1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    
    return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    // heights is 0-indexed so, we passed n-1
    return f(n-1, heights, dp);
}

// tabulation
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    
    for (int i=1; i<n; i++) {
        int prev2 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int prev = INT_MAX;
        if (i > 1) prev = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(prev2, prev);
    }
    return dp[n-1];
}
// optimised
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev2 = 0, prev = 0, curr = 0;
    for (int i=1; i<n; i++) {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if (i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);
        
        curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// https://www.geeksforgeeks.org/problems/geek-jump/1
// memiozation
class Solution {
  private:
    int f(int ind, vector<int>& heights, vector<int>& dp) {
        if (ind == 0) return 0;
        if (dp[ind] != -1) return dp[ind];
    
        int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
        int right = INT_MAX;
        if (ind > 1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
        
        return dp[ind] = min(left, right);
    }
  public:
    int minCost(vector<int> &heights) {
        int n = heights.size();
        vector<int> dp(n+1, -1);
        // heights is 0-indexed so, we passed n-1
        return f(n-1, heights, dp);
    }
};
// tabulation
class Solution {
  public:
    int minCost(vector<int> &heights) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        
        for (int i=1; i<n; i++) {
            int prev2 = dp[i-1] + abs(heights[i] - heights[i-1]);
            int prev = INT_MAX;
            if (i > 1) prev = dp[i-2] + abs(heights[i] - heights[i-2]);
            
            dp[i] = min(prev2, prev);
        }
        return dp[n-1];
    }
};
// optimised
class Solution {
  public:
    int minCost(vector<int> &heights) {
        int n = heights.size();
        int prev2 = 0, prev = 0, curr = 0;
        for (int i=1; i<n; i++) {
            int fs = prev + abs(heights[i] - heights[i-1]);
            int ss = INT_MAX;
            if (i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);
            
            curr = min(fs, ss);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};