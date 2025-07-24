// https://www.naukri.com/code360/problems/longest-common-substring_1214702
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://www.youtube.com/watch?v=_wP9mWNPL5w

// tabulation - after the shifting of index, we can now write tabulation
int LCSubStr(string &s, string &t) {
    int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	for (int ind2=0; ind2<=m; ind2++) dp[0][ind2] = 0;
	for (int ind1=0; ind1<=n; ind1++) dp[ind1][0] = 0;

    int ans = 0;
	for (int ind1=1; ind1<=n; ind1++) {
		for (int ind2=1; ind2<=m; ind2++) {
			if (s[ind1-1] == t[ind2-1]) {
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                ans = max(ans, dp[ind1][ind2]);
            }
			else dp[ind1][ind2] = 0;
		}
	}
    return ans;
}

// optimized
int LCSubStr(string &s, string &t) {
    int n = s.size(), m = t.size();
	vector<int> prev(m+1, 0), curr(m+1, 0);

	int ans = 0;
	for (int ind1=1; ind1<=n; ind1++) {
		for (int ind2=1; ind2<=m; ind2++) {
			if (s[ind1-1] == t[ind2-1]) {
				curr[ind2] = 1 + prev[ind2-1];
				ans = max(ans, curr[ind2]);
			}
			else curr[ind2] = 0;
		}
		prev = curr;
	}
	return ans;
}