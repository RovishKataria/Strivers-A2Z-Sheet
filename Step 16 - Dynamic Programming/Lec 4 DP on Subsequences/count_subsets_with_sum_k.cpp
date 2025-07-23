// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// https://www.youtube.com/watch?v=ZHyb-A2Mte4

// memoization
const int mod = 1e9 + 7;
int f(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp) {
	// if (sum == 0) return 1;
	if (ind == 0) {
		if (sum == 0 && arr[0] == 0) return 2;
		if (sum == 0 || arr[0] == sum) return 1;
		return 0;
	}
	if (dp[ind][sum] != -1) return dp[ind][sum];
	
	int not_take = f(ind-1, sum, arr, dp);
	int take = 0;
	if (arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr, dp);

	return dp[ind][sum] = (not_take + take) % mod;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}

// tabulation
const int mod = 1e9 + 7;
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	// below 3 lines i did and these work fine.
	// for (int i=0; i<n; i++) dp[i][0] = 1;
	// if (arr[0] <= k) dp[0][arr[0]] = 1;
	// if (arr[0] == 0) dp[0][0] = 2;
	
	// below 3 lines striver did
	if(arr[0] == 0) dp[0][0] = 2;
	else dp[0][0] = 1;
	// we added arr[0] != 0 because what if arr[0] == 0 then it will become 1
	if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

	for (int ind=1; ind<n; ind++) {
		for (int sum=0; sum<=k; sum++) {
			int not_take = dp[ind-1][sum];
			int take = 0;
			if (arr[ind] <= sum) take = dp[ind-1][sum-arr[ind]];
			dp[ind][sum] = (not_take + take) % mod;
		}
	}

	return dp[n-1][k];
}

// optimized
const int mod = 1e9 + 7;
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);
	// prev[0] = 1;
	// curr[0] = 1;
	// if (arr[0] <= k) prev[arr[0]] = 1;
	// below 1 lines i did and work fine.
	// if (arr[0] == 0) prev[0] = 2;

	// below 3 lines striver did
	if(arr[0] == 0) prev[0] = 2;
	else prev[0] = 1;
	// we added arr[0] != 0 because what if arr[0] == 0 then it will become 1
	if (arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

	for (int ind=1; ind<n; ind++) {
		for (int sum=0; sum<=k; sum++) {
			int not_take = prev[sum];
			int take = 0;
			if (arr[ind] <= sum) take = prev[sum-arr[ind]];
			curr[sum] = (not_take + take) % mod;
		}
		prev = curr;
	}
	return prev[k];
}