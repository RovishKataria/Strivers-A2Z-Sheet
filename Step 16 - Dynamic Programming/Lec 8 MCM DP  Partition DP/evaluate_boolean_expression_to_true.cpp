// https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650
// https://www.youtube.com/watch?v=MM7fXopgyjw

int mod = 1000000007;
int f(int i, int j, int isTrue, string &arr, vector<vector<vector<int>>>& dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return arr[i] == 'T' ? 1 : 0;
        else return arr[i] == 'F' ? 1 : 0;
    }
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for (int ind=i+1; ind<=j-1; ind += 2) {
        int lT = f(i, ind-1, 1, arr, dp);
        int lF = f(i, ind-1, 0, arr, dp);
        int rT = f(ind+1, j, 1, arr, dp);
        int rF = f(ind+1, j, 0, arr, dp);

        if (arr[ind] == '&') {
            if (isTrue) ways = (ways + (1LL * lT * rT) % mod) % mod;
            else ways = (ways + (1LL * lF * rT) % mod +
                                (1LL * lT * rF) % mod +
                                (1LL * lF * rF) % mod) % mod;
        }
        else if (arr[ind] == '|') {
            if (isTrue) ways = (ways + (1LL * lT * rF) % mod +
                                        (1LL * lF * rT) % mod +
                                        (1LL * lT * rT) % mod) % mod;
            else ways = (ways + (1LL * lF * rF) % mod) % mod;
        }
        else {
            if (isTrue) ways = (ways + (1LL * lF * rT) % mod +
                            (1LL * lT * rF) % mod) % mod;
            else ways = (ways + (1LL * lT * rT) % mod +
                            (1LL * lF * rF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
    }
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
    return f(0, n-1, 1, exp, dp);
}

// tabulation - needs to do by yourself
