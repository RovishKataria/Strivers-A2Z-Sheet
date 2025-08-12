// https://www.naukri.com/code360/problems/occurs-once_1214969
// https://www.geeksforgeeks.org/problems/single-number1014/1
// https://leetcode.com/problems/single-number/description/
// https://www.youtube.com/watch?v=sFBCAl8yBfE

#include <bits/stdc++.h> 
int occursOnce(vector<int> &a, int n) {
	int ans = 0;
	for (int i=0; i<n; i++) {
		ans ^= a[i];
	}
	return ans;
}
