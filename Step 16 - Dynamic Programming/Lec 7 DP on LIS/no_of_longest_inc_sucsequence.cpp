// https://www.naukri.com/code360/problems/number-of-longest-increasing-subsequence_3751627
// https://www.geeksforgeeks.org/problems/number-of-longest-increasing-subsequence/1
// https://www.naukri.com/code360/problems/number-of-longest-increasing-subsequence_3751627
// https://www.youtube.com/watch?v=cKVl1TFdNXg

int findNumberOfLIS(vector<int> &arr) {
    int n = arr.size();
	vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;
	
	for (int ind=0; ind<n; ind++) {
		for (int pind=0; pind<ind; pind++) {
			if (arr[pind] < arr[ind] && 1+dp[pind] > dp[ind]) {
				dp[ind] = 1 + dp[pind];
                cnt[ind] = cnt[pind];
			}
            // someone with same length -- inc the count
            else if (arr[pind] < arr[ind] && 1+dp[pind] == dp[ind]) {
                cnt[ind] += cnt[pind];
            }
		}
        maxi = max(maxi, dp[ind]);
	}

    int nos = 0;
    for (int i=0; i<n; i++) {
        if (dp[i] == maxi) nos += cnt[i];
    }
    return nos;
}