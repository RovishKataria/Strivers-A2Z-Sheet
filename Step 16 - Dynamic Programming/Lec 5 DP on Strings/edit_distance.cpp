// https://leetcode.com/problems/edit-distance/description/
// https://www.geeksforgeeks.org/problems/edit-distance3702/1
// https://www.naukri.com/code360/problems/edit-distance_630420
// https://www.youtube.com/watch?v=fJaKO8FbDdo

// memoization - TLE
int f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if (j<0) return i+1;
    if (i<0) return j+1;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);
    int ins_op = 1 + f(i, j-1, s1, s2, dp);
    int del_op = 1 + f(i-1, j, s1, s2, dp);
    int rep_op = 1 + f(i-1, j-1, s1, s2, dp);

    return dp[i][j] = min(ins_op, min(del_op, rep_op));
}
int editDistance(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n-1, m-1, str1, str2, dp);
}

// 0-based indexed
int f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if (j==0) return i;
    if (i==0) return j;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i-1] == s2[j-1]) return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);
    int ins_op = 1 + f(i, j-1, s1, s2, dp);
    int del_op = 1 + f(i-1, j, s1, s2, dp);
    int rep_op = 1 + f(i-1, j-1, s1, s2, dp);

    return dp[i][j] = min(ins_op, min(del_op, rep_op));
}
int editDistance(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    return f(n, m, str1, str2, dp);
}

// tabulation
int editDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for (int i=0; i<=n; i++) dp[i][0] = i;
    for (int j=0; j<=m; j++) dp[0][j] = j;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 0 + dp[i-1][j-1];
            else {
                int ins_op = 1 + dp[i][j-1];
                int del_op = 1 + dp[i-1][j];
                int rep_op = 1 + dp[i-1][j-1];
                dp[i][j] = min(ins_op, min(del_op, rep_op));
            }

        }
    }

    return dp[n][m];
}

// optimized
int editDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for (int j=0; j<=m; j++) prev[j] = j;

    for (int i=1; i<=n; i++) {
        curr[0] = i;
        for (int j=1; j<=m; j++) {
            if (s1[i-1] == s2[j-1])
                curr[j] = 0 + prev[j-1];
            else {
                int ins_op = 1 + curr[j-1];
                int del_op = 1 + prev[j];
                int rep_op = 1 + prev[j-1];
                curr[j] = min(ins_op, min(del_op, rep_op));
            }
        }
        prev = curr;
    }
    return prev[m];
}