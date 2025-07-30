// https://leetcode.com/problems/valid-parenthesis-string/description/
// https://www.youtube.com/watch?v=cHT6sG_hUZI

// Another good approach
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mini = 0, maxi = 0;
        for (int ind=0; ind<n; ind++) {
            if (s[ind] == '(') {
                mini++; maxi++;
            } else if (s[ind] == ')') {
                mini--; maxi--;
            } else {
                mini--; maxi++;
            }
            if (mini < 0) mini = 0;
            if (maxi < 0) return false;
        }
        return mini == 0;
    }
};

// memoization
class Solution {
private:
    bool f(string s, int n, int ind, int cnt, vector<vector<int>>& dp) {
        if (cnt < 0) return false;
        if (ind == n) return (cnt == 0);
        if (dp[ind][cnt] != -1) return dp[ind][cnt];
        if (s[ind] == '(') return dp[ind][cnt] = f(s, n, ind+1, cnt+1, dp);
        if (s[ind] == ')') return dp[ind][cnt] = f(s, n, ind+1, cnt-1, dp);
        return dp[ind][cnt] = (f(s, n, ind+1, cnt+1, dp) ||
                                f(s, n, ind+1, cnt-1, dp) || f(s, n, ind+1, cnt, dp));
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(s, n, 0, 0, dp);
    }
};

// tabulation
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[n][0] = 1;

        for (int ind=n-1; ind>=0; ind--) {
            for (int cnt=0; cnt<=n; cnt++) {
                if (s[ind] == '(') {
                    if (cnt+1 <= n) dp[ind][cnt] = dp[ind+1][cnt+1];
                }
                else if (s[ind] == ')') {
                    if (cnt > 0) dp[ind][cnt] = dp[ind+1][cnt-1];
                }
                else {
                    bool opt1 = (cnt + 1 <= n) ? dp[ind + 1][cnt + 1] : 0;
                    bool opt2 = (cnt > 0) ? dp[ind + 1][cnt - 1] : 0;
                    bool opt3 = dp[ind + 1][cnt];
                    dp[ind][cnt] = opt1 || opt2 || opt3;
                }
            }
        }
        return dp[0][0];
    }
};

// space optimized
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        prev[0] = 1;

        for (int ind=n-1; ind>=0; ind--) {
            for (int cnt=0; cnt<=n; cnt++) {
                if (s[ind] == '(') {
                    if (cnt+1 <= n) curr[cnt] = prev[cnt+1];
                    else curr[cnt] = 0;
                }
                else if (s[ind] == ')') {
                    if (cnt > 0) curr[cnt] = prev[cnt-1];
                    else curr[cnt] = 0;
                }
                else {
                    bool opt1 = (cnt + 1 <= n) ? prev[cnt + 1] : 0;
                    bool opt2 = (cnt > 0) ? prev[cnt - 1] : 0;
                    bool opt3 = prev[cnt];
                    curr[cnt] = opt1 || opt2 || opt3;
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};
