// https://www.naukri.com/code360/problems/rod-cutting-problem_800284
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// https://www.youtube.com/watch?v=mO8XpGoJwuo

// memiozation
int f(int ind, int N, vector<int>& price, vector<vector<int>>& dp) {
	if (ind == 0) return (N * price[0]);
	if (dp[ind][N] != -1) return dp[ind][N];

	int not_take = 0 + f(ind-1, N, price, dp);
	int take = INT_MIN;
	int rod_length = ind + 1;
	if (rod_length <= N) take = price[ind] + f(ind, N-rod_length, price, dp);

	return dp[ind][N] = max(take, not_take);
}
int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return f(n-1, n, price, dp);
}

// tabulation
int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int> (n+1, 0));
	for (int N=0; N<=n; N++) dp[0][N] = N * price[0];

	for (int ind=1; ind<n; ind++) {
		for (int N=0; N<=n; N++) {
			int not_take = 0 + dp[ind-1][N];
			int take = INT_MIN;
			int rod_length = ind + 1;
			if (rod_length <= N) take = price[ind] + dp[ind][N - rod_length];

			dp[ind][N] = max(take, not_take);
		}
	}

	return dp[n-1][n];
}

// optimized
int cutRod(vector<int> &price, int n) {
	vector<int> prev(n+1, 0), curr(n+1, 0);
	for (int N=0; N<=n; N++) prev[N] = N * price[0];

	for (int ind=1; ind<n; ind++) {
		for (int N=0; N<=n; N++) {
			int not_take = 0 + prev[N];
			int take = INT_MIN;
			int rod_length = ind + 1;
			if (rod_length <= N) take = price[ind] + curr[N - rod_length];

			curr[N] = max(take, not_take);
		}
		prev = curr;
	}

	return prev[n];
}

// optimized 1 array
int cutRod(vector<int> &price, int n) {
	vector<int> prev(n+1, 0);
	for (int N=0; N<=n; N++) prev[N] = N * price[0];

	for (int ind=1; ind<n; ind++) {
		for (int N=0; N<=n; N++) {
			int not_take = 0 + prev[N];
			int take = INT_MIN;
			int rod_length = ind + 1;
			if (rod_length <= N) take = price[ind] + prev[N - rod_length];

			prev[N] = max(take, not_take);
		}
	}

	return prev[n];
}
