// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// https://www.youtube.com/watch?v=GS_OqZb2CWc
// similar to subset_sum_equal_to_target with only tabulation part.

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int total_sum = 0;
	for (int i=0; i<n; i++) total_sum += arr[i];
	int k = total_sum;
	vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for (int i=0; i<n; i++) dp[i][0] = true;
    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int ind=1; ind<n; ind++) {
        for (int target=1; target<=k; target++) {
            bool not_take = dp[ind-1][target];
            bool take = false;
            if (arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
            
            dp[ind][target] = take | not_take;
        }
    }

	int mini = 1e9;
	for (int s1=0; s1<=total_sum/2; s1++) {
		if (dp[n-1][s1] == true)
			mini = min(mini, abs(s1 - (total_sum-s1)));
	}
	return mini;
}
