// https://www.naukri.com/code360/problems/printing-longest-increasing-subsequence_8360670
// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
// https://www.youtube.com/watch?v=IFfYfonAFGc

vector<int> printingLongestIncreasingSubsequence(vector<int> heights, int n) {
	vector<int> dp(n, 1), hash(n);
	int maxi = 1;
	int last_ind = 0;

	for (int ind=0; ind<n; ind++) {
		hash[ind] = ind;
		for (int pind=0; pind<=ind-1; pind++) {
			if (heights[pind] < heights[ind] &&
				1 + dp[pind] > dp[ind]) {
				dp[ind] = max(1 + dp[pind], dp[ind]);
				hash[ind] = pind;
			}
		}
		if (dp[ind] > maxi) {
			maxi = max(maxi, dp[ind]);
			last_ind = ind;
		}
	}
	
	vector<int> lis;
	lis.push_back(heights[last_ind]);
	while (hash[last_ind] != last_ind) {
		last_ind = hash[last_ind];
		lis.push_back(heights[last_ind]);
	}
	
	reverse(lis.begin(), lis.end());
	return lis;
}
