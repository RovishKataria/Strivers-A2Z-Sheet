// https://www.naukri.com/code360/problems/longest-increasing-subsequence_1062665
// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// https://leetcode.com/problems/longest-increasing-subsequence/description/
// https://www.youtube.com/watch?v=ekcwMsSIzVc

// memoization
#include <bits/stdc++.h> 
int f(int ind, int pind, vector<int> &heights, int n, vector<vector<int>>& dp) {
	if (ind == n) return 0;
	if (dp[ind][pind+1] != -1) return dp[ind][pind+1];
	
	int not_take = 0 + f(ind+1, pind, heights, n, dp);
	int take = INT_MIN;
	if (pind == -1 || heights[ind] > heights[pind])
		take = 1 + f(ind+1, ind, heights, n, dp);

	return dp[ind][pind+1] = max(not_take, take);
}
int LIS(vector<int> &heights, int n){
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return f(0, -1, heights, n, dp);
}

// tabulation
#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){
	vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

	for (int ind=n-1; ind>=0; ind--) {
		for (int pind=ind-1; pind>=-1; pind--) {
			int not_take = 0 + dp[ind+1][pind+1];
			int take = INT_MIN;
			if (pind == -1 || heights[ind] > heights[pind])
				take = 1 + dp[ind+1][ind+1];

			dp[ind][pind+1] = max(not_take, take);
		}
	}
	return dp[0][-1+1];
}

// optimized
#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){
	vector<int> next(n+1, 0), curr(n+1, 0);

	for (int ind=n-1; ind>=0; ind--) {
		for (int pind=ind-1; pind>=-1; pind--) {
			int not_take = 0 + next[pind+1];
			int take = INT_MIN;
			if (pind == -1 || heights[ind] > heights[pind])
				take = 1 + next[ind+1];

			curr[pind+1] = max(not_take, take);
		}
		next = curr;
	}
	return next[-1+1];
}

// Another solution with TC=O(n^2) ans SC=O(n)
// this solution is required while tracing back the LIS
#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){
	vector<int> dp(n, 1);
	int maxi = 1;
	for (int ind=0; ind<n; ind++) {
		for (int pind=0; pind<=ind-1; pind++) {
			if (heights[pind] < heights[ind])
				dp[ind] = max(1 + dp[pind], dp[ind]);
		}
		maxi = max(maxi, dp[ind]);
	}
	return maxi;
}

// using binary search
#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){
	vector<int> temp;
	temp.push_back(heights[0]);
	int len = 1;

	for (int i=1; i<n; i++) {
		if (heights[i] > temp.back()) {
			temp.push_back(heights[i]);
			len++;
		}
		else {
			int ind = lower_bound(temp.begin(), temp.end(), heights[i]) - temp.begin();
			temp[ind] = heights[i];
		}
	}
	return len;
}
