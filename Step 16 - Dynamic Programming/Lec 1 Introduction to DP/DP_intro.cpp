// https://www.geeksforgeeks.org/problems/introduction-to-dp/1
// https://www.youtube.com/watch?v=tyB0ztf0DNY

class Solution {
  public:
    const long long int MOD = 1e9 + 7;
    // memoization
    long long int f(int n, vector<long long int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = (f(n-1, dp) + f(n-2, dp)) % MOD;
    }
    long long int topDown(int n) {
        vector<long long int> dp(n+1, -1);
        return f(n, dp);
    }

    // tabulation
    long long int bottomUp(int n) {
        if (n <= 1) return n;
        long long int prev2 = 0, prev = 1;
        for (int i=2; i<=n; i++) {
            long long int curri = (prev2 + prev) % MOD;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
