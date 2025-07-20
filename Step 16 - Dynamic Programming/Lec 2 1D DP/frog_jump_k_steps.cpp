// https://www.geeksforgeeks.org/problems/minimal-cost/1
// https://www.youtube.com/watch?v=Kmh3rhyEtB8

// memiozation
class Solution {
  private:
    int f(int ind, int k, vector<int>& arr, vector<int>& dp) {
        if (ind == 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        
        int min_cost = INT_MAX;
        for (int i=1; i<=k; i++) {
            if (ind-i >= 0) {
                int jump = f(ind-i, k, arr, dp) + abs(arr[ind] - arr[ind-i]);
                min_cost = min(min_cost, jump);
            }
        }
        return dp[ind] = min_cost;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(n-1, k, arr, dp);
    }
};

// tabulation
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        for (int i=1; i<n; i++) {
            int min_jumps = INT_MAX;
            for (int j=1; j<=k; j++) {
                if (i-j >= 0) {
                    int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                    min_jumps = min(min_jumps, jump);
                }
            }
            dp[i] = min_jumps;
        }
        
        return dp[n-1];
    }
};