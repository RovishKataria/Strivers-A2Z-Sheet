// https://www.youtube.com/watch?v=-zI4mrF2Pb4

// tabulation - after the shifting of index, then backtracking on dp
vector<string> allLCS(string &s, string &t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	for (int ind2=0; ind2<=m; ind2++) dp[0][ind2] = 0;
	for (int ind1=0; ind1<=n; ind1++) dp[ind1][0] = 0;

	for (int ind1=1; ind1<=n; ind1++) {
		for (int ind2=1; ind2<=m; ind2++) {
			if (s[ind1-1] == t[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
			else dp[ind1][ind2] = (0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]));
		}
	}
	
	int ind = dp[n][m] - 1;
	vector<string> ans(ind+1);
	
	int i=n, j=m;
	// row1 and col1 are no use to us
	while (i>0 && j>0) {
		if (s[i-1] == t[j-1]) {
			ans[ind] = s[i-1];
			ind--; i--; j--;
		}
		else if (dp[i][j-1] > dp[i-1][j]) j--;
		else i--;
	}
	
	return ans;
}