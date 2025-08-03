// https://www.naukri.com/code360/problems/minimum-window-subsequence_2181133
// https://leetcode.com/problems/minimum-window-subsequence/description/

string minWindow(string s, string t) {
	int n = s.size(), m = t.size();
	if (m > n) return "";
	int s1 = 0, minlen = 1e9, start = -1;
	while (s1 < n) {
		int t1 = 0;
		// find t in s
		while (s1 < n) {
			if (s[s1] == t[t1]) {
				t1++;
				if (t1 == m) break;
			}
			s1++;
		}
		if (t1 < m) break; //t is not in s

		int end = s1;
		t1 = m-1;
		while (t1 >= 0) {
			if (s[s1] == t[t1]) t1--;
			s1--;
		}
		s1++;
		if (end-s1+1 < minlen) {
			minlen = end-s1+1;
			start = s1;
		}
		s1++;
	}
	return (start == -1) ? "" : s.substr(start, minlen);
}
