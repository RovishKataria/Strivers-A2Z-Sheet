// https://www.naukri.com/code360/problems/minimum-insertions-to-make-a-string-palindrome_985293
// https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
// https://www.youtube.com/watch?v=xPBLEj41rFU

#include<bits/stdc++.h>
int lcs(string s, string t) {
	int n = s.size(), m = t.size();
	vector<int> prev(m+1, 0), curr(m+1, 0);
	for (int ind2=0; ind2<=m; ind2++) prev[ind2] = 0;

	for (int ind1=1; ind1<=n; ind1++) {
		for (int ind2=1; ind2<=m; ind2++) {
			if (s[ind1-1] == t[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
			else curr[ind2] = (0 + max(prev[ind2], curr[ind2-1]));
		}
		prev = curr;
	}
	return prev[m];
}
int minimumInsertions(string &s) {
	string t = s;
	reverse(t.begin(), t.end());
	return s.size() - lcs(s, t);
}
