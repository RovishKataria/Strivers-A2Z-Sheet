// https://www.naukri.com/code360/problems/maze-obstacles_977241
// https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1
// https://leetcode.com/problems/unique-paths-ii/description/
// https://www.youtube.com/watch?v=TmhpgXScLyY

// memoization
const int MOD = 1e9 + 7;
int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (i>=0 && j>=0 && mat[i][j] == -1) return 0;
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int up = f(i-1, j, mat, dp);
    int left = f(i, j-1, mat, dp);
    return dp[i][j] = (up + left) % MOD;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1, mat, dp);
}

// tabulation
const int MOD = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if (mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == -1) dp[i][j]=0;
            else if (i==0 && j==0) dp[i][j] = 1;
            else {
                int up=0, left=0;
                if (i>0) up = (dp[i-1][j]) % MOD;
                if (j>0) left = (dp[i][j-1]) % MOD;
                dp[i][j] = (up + left) % MOD;
            }
        }
    }
    return dp[n-1][m-1];
}

// optimized
const int MOD = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if (mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    vector<int> prev(m, 0);
    for (int i=0; i<n; i++) {
        vector<int> curr(m, 0);
        for (int j=0; j<m; j++) {
            if (mat[i][j] == -1) curr[j]=0;
            else if (i==0 && j==0) curr[j] = 1;
            else {
                int up=0, left=0;
                if (i>0) up = prev[j];
                if (j>0) left = curr[j-1];
                curr[j] = (up + left) % MOD;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}