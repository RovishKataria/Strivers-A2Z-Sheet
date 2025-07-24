// https://www.naukri.com/code360/problems/subsequence-counting_3755256
// https://leetcode.com/problems/distinct-subsequences/description/
// https://www.youtube.com/watch?v=nVG7eTiD2bY

// memiozation
class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        if (j<0) return 1;
        if (i<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        else return dp[i][j] = f(i-1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        return f(n-1, m-1, s, t, dp);
    }
};

// memoization with index shift as 0-based indexing is there
class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        if (j==0) return 1;
        if (i==0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i-1] == t[j-1])
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        else return dp[i][j] = f(i-1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s, t, dp);
    }
};

// tabulation

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        for (int i=0; i<=n; i++) dp[i][0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return (int)dp[n][m];
    }
};

// vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
// the above was giving overflow so
// vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
// still overflow
// vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
// return (int)dp[n][m];

// optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0), curr(m+1, 0);
        prev[0] = 1;
        curr[0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        
        return (int)prev[m];
    }
};

// optimized -> 1 array
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0);
        prev[0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=m; j>=1; j--) {
                if (s[i-1] == t[j-1])
                    prev[j] = prev[j-1] + prev[j];
                else prev[j] = prev[j];
            }
        }
        
        return (int)prev[m];
    }
};