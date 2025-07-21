// https://www.naukri.com/code360/problems/total-unique-paths_1081470
// https://www.geeksforgeeks.org/problems/number-of-paths0926/1
// https://leetcode.com/problems/unique-paths/description/
// https://www.youtube.com/watch?v=sdE0A2Oxofw

// memoization
#include <bits/stdc++.h> 
int f(int row, int col, vector<vector<int>>& dp) {
	if (row == 0 && col == 0) return 1;
	if (row < 0 || col < 0) return 0;
	if (dp[row][col] != -1) return dp[row][col];

	int up = f(row-1, col, dp);
	int left = f(row, col-1, dp);
	return dp[row][col] = up+left;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return f(m-1, n-1, dp);
}

// tabulation
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	dp[0][0] = 1;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (i==0 && j==0) dp[i][j] = 1;
			else {
				int up = 0, left = 0;
				if (i>0) up = dp[i-1][j];
				if (j>0) left = dp[i][j-1];
				dp[i][j] = up+left;
			}
		}
	}
	return dp[m-1][n-1];
}

// optimized
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<int> prev(n, 0);
	for (int i=0; i<m; i++) {
		vector<int> curr(n, 0);
		for (int j=0; j<n; j++) {
			if (i==0 && j==0) curr[j] = 1;
			else {
				int up = 0, left = 0;
				if (i>0) up = prev[j];
				if (j>0) left = curr[j-1];
				curr[j] = up + left;
			}
		}
		prev = curr;
	}
	return prev[n-1];
}

// more optimized for google
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// combination = NCr
	int N = m + n - 2;
	int r = m - 1;
	long long int res = 1;
	for (int i=1; i<=r; i++) {
		res = res * (N - r + i) / i;
	}
	return res;
}