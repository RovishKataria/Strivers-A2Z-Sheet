// https://www.naukri.com/code360/problems/longest-common-subsequence_624879
// https://leetcode.com/problems/longest-common-subsequence/description/
// https://www.youtube.com/watch?v=NPZn9jBrX8U

// memoization
#include<bits/stdc++.h>
int f(int ind1, int ind2, string &s, string &t, vector<vector<int>>& dp) {
	if (ind1<0 || ind2<0) return 0;
	if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
	if (s[ind1] == t[ind2]) return 1 + f(ind1-1, ind2-1, s, t, dp);
	return dp[ind1][ind2] = (0 + max(f(ind1-1, ind2, s, t, dp), f(ind1, ind2-1, s, t, dp)));
}
int lcs(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n, vector<int> (m, -1));
	return f(n-1, m-1, s, t, dp);
}
// can be written using shifting of index
#include<bits/stdc++.h>
int f(int ind1, int ind2, string &s, string &t, vector<vector<int>>& dp) {
	if (ind1==0 || ind2==0) return 0;
	if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
	if (s[ind1-1] == t[ind2-1]) return 1 + f(ind1-1, ind2-1, s, t, dp);
	return dp[ind1][ind2] = (0 + max(f(ind1-1, ind2, s, t, dp), f(ind1, ind2-1, s, t, dp)));
}
int lcs(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	return f(n, m, s, t, dp);
}
// tabulation - after the shifting of index, we can now write tabulation
#include<bits/stdc++.h>
int lcs(string s, string t) {
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
	return dp[n][m];
}

// optimized
#include<bits/stdc++.h>
int lcs(string s, string t) {
	int n = s.size(), m = t.size();
	vector<int> prev(m+1, 0), curr(m+1, 0);
	for (int ind2=0; ind2<=m; ind2++) prev[ind2] = 0;

	for (int ind1=1; ind1<=n; ind1++) {
		for (int ind2=1; ind2<=m; ind2++) {
			if (s[ind1-1] == t[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
			else curr[ind2] = (0 + max(prev[ind2], curr[ind2-1]));
		}
		prev = curr;
	}
	return prev[m];
}