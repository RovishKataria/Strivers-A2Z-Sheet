// https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688
// https://www.youtube.com/watch?v=y4vN0WNdrlg

#include <bits/stdc++.h> 
int longestBitonicSubsequence(vector<int>& arr, int n) {
	vector<int> dp1(n, 1);
	// left to right
	for (int ind=0; ind<n; ind++) {
		for (int pind=0; pind<ind; pind++) {
			if (arr[pind] < arr[ind] && 1 + dp1[pind] > dp1[ind]) {
				dp1[ind] = 1 + dp1[pind];
			}
		}
	}

	// right to left
	vector<int> dp2(n, 1);
	for (int ind=n-1; ind>=0; ind--) {
		for (int pind=n-1; pind>ind; pind--) {
			if (arr[pind] < arr[ind] && 1 + dp2[pind] > dp2[ind]) {
				dp2[ind] = 1 + dp2[pind];
			}
		}
	}

	int maxi = 0;
	for (int i=0; i<n; i++) {
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}
	return maxi;
}
