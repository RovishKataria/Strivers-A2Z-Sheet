// https://www.naukri.com/code360/problems/can-you-make_4244510
// https://www.youtube.com/watch?v=yMnH0jrir0Q

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
int canYouMake(string &s1, string &s2){
    return (s1.size() + s2.size() - (2 * lcs(s1, s2)));
}