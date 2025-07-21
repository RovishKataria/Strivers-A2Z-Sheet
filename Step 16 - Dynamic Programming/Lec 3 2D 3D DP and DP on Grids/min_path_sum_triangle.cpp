// https://www.naukri.com/code360/problems/triangle_1229398
// https://www.geeksforgeeks.org/problems/triangle-path-sum/1
// https://leetcode.com/problems/triangle/description/
// https://www.youtube.com/watch?v=SrP-PiLSYC0

// recursion
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>& triangle, int n) {
	if (i==n-1) return triangle[i][j];
	if (j >= i+1) return 1e9;
	int down = triangle[i][j] + f(i+1, j, triangle, n);
	int down_right = triangle[i][j] + f(i+1, j+1, triangle, n);
	return min(down, down_right);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return f(0, 0, triangle, n);
}

// memoization
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> dp) {
	if (i==n-1) return triangle[n-1][j];
	if (dp[i][j] != -1) return dp[i][j];
	int down = triangle[i][j] + f(i+1, j, triangle, n, dp);
	int down_right = triangle[i][j] + f(i+1, j+1, triangle, n, dp);
	return dp[i][j] = min(down, down_right);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return f(0, 0, triangle, n, dp);
}

// tabulation
#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];

	for (int i=n-2; i>=0; i--) {
		for (int j=i; j>=0; j--) {
			int down = triangle[i][j] + dp[i+1][j];
			int down_right = triangle[i][j] + dp[i+1][j+1];
			dp[i][j] = min(down, down_right);
		}
	}

	return dp[0][0];
}

// optimized
#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> front(n, 0);
	for (int j=0; j<n; j++) front[j] = triangle[n-1][j];

	for (int i=n-2; i>=0; i--) {
		vector<int> curr(n, 0);
		for (int j=i; j>=0; j--) {
			int down = triangle[i][j] + front[j];
			int down_right = triangle[i][j] + front[j+1];
			curr[j] = min(down, down_right);
		}
		front = curr;
	}

	return front[0];
}

// recursion from end
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>& triangle) {
	if (i==0 && j==0) return triangle[0][0];
	if (i<0 || j<0 || j >= i+1) return 1e9;
	int up = triangle[i][j] + f(i-1, j, triangle);
	int up_left = triangle[i][j] + f(i-1, j-1, triangle);
	return min(up, up_left);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	int mini = INT_MAX;
	for (int i=0; i<n; i++) {
		mini = min(mini, f(n-1, i, triangle));
	}
	return mini;
}