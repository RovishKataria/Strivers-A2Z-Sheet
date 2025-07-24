// https://www.naukri.com/code360/problems/longest-string-chain_3752111
// https://www.geeksforgeeks.org/problems/longest-string-chain/1
// https://leetcode.com/problems/longest-string-chain/description/
// https://www.youtube.com/watch?v=YY8iBaYcc4g

bool checkPossible(string &s1, string &s2) {
	if (s1.size() != s2.size() + 1) return false;
	int first = 0, second = 0;

	while (first < s1.size()) {
		if (second < s2.size() && s1[first] == s2[second]){
			first++; second++;
		}
		else {
			first++;
		}
	}

	if (first == s1.size() && second == s2.size()) return true;
	return false;
}
static bool comp(string &s1, string &s2) {
	return s1.size() < s2.size();
}
int longestStrChain(vector<string> &arr){
	sort(arr.begin(), arr.end(), comp);
	int n = arr.size();
	vector<int> dp(n, 1);
	int maxi = 1;

	for (int ind=0; ind<n; ind++) {
		for (int pind=0; pind<ind; pind++) {
			if (checkPossible(arr[ind], arr[pind]) &&
				1 + dp[pind] > dp[ind]) {
				dp[ind] = max(1 + dp[pind], dp[ind]);
			}
		}
		maxi = max(maxi, dp[ind]);
	}
	return maxi;
}