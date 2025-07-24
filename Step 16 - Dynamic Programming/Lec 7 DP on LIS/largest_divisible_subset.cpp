// https://www.naukri.com/code360/problems/divisible-set_3754960
// https://leetcode.com/problems/largest-divisible-subset/description/
// https://www.youtube.com/watch?v=gDuZwBW9VvM

// similar to LIS using binary searcrh

vector<int> divisibleSet(vector<int> &arr) {
	int n = arr.size();
    sort(arr.begin(), arr.end());
	vector<int> dp(n, 1), hash(n);
	int maxi = 1;
	int last_ind = 0;
	
	for (int ind=0; ind<n; ind++) {
		hash[ind] = ind;
		for (int pind=0; pind<=ind-1; pind++) {
			if (arr[ind] % arr[pind] == 0 &&
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
	lis.push_back(arr[last_ind]);
	while (hash[last_ind] != last_ind) {
		last_ind = hash[last_ind];
		lis.push_back(arr[last_ind]);
	}
	
	reverse(lis.begin(), lis.end());
	return lis;
}