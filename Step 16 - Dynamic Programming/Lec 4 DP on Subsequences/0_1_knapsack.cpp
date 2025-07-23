// https://www.naukri.com/code360/problems/0-1-knapsack_920542
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// https://www.youtube.com/watch?v=GqOmJHQZivw

// memoization
#include <bits/stdc++.h>
int f(int ind, int W, vector<int>& value, vector<int>& weight, vector<vector<int>>& dp) {
	if (ind == 0) {
		if (weight[0] <= W) return value[0];
		return 0;
	}
	if (dp[ind][W] != -1) return dp[ind][W];
	
	int not_take = 0 + f(ind-1, W, value, weight, dp);
	int take = INT_MIN;
	if (weight[ind] <= W)
		take = value[ind] + f(ind-1, W - weight[ind], value, weight, dp);

	return dp[ind][W] = max(not_take, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	return f(n-1, maxWeight, value, weight, dp);
}

// tabulation
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
	// for evrey wt[0] > we ccan steal it;
	for (int i=weight[0]; i<=maxWeight; i++) dp[0][i] = value[0];

	for (int ind=1; ind<n; ind++) {
		for (int W=0; W<=maxWeight; W++) {
			int not_take = 0 + dp[ind-1][W];
			int take = INT_MIN;
			if (weight[ind] <= W)
				take = value[ind] + dp[ind-1][W - weight[ind]];
			dp[ind][W] = max(not_take, take);
		}
	}
	return dp[n-1][maxWeight];
}

// optimized
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
	// for evrey wt[0] > we ccan steal it;
	for (int i=weight[0]; i<=maxWeight; i++) prev[i] = value[0];

	for (int ind=1; ind<n; ind++) {
		for (int W=0; W<=maxWeight; W++) {
			int not_take = 0 + prev[W];
			int take = INT_MIN;
			if (weight[ind] <= W)
				take = value[ind] + prev[W - weight[ind]];
			curr[W] = max(not_take, take);
		}
		prev = curr;
	}
	return prev[maxWeight];
}

// optimized with 1 row
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight+1, 0);
	// for evrey wt[0] > we ccan steal it;
	for (int i=weight[0]; i<=maxWeight; i++) prev[i] = value[0];

	for (int ind=1; ind<n; ind++) {
		for (int W=maxWeight; W>=0; W--) {
			int not_take = 0 + prev[W];
			int take = INT_MIN;
			if (weight[ind] <= W)
				take = value[ind] + prev[W - weight[ind]];
			prev[W] = max(not_take, take);
		}
	}
	return prev[maxWeight];
}