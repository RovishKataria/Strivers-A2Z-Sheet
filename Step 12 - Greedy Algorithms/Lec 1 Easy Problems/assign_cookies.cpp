// https://www.naukri.com/code360/problems/assign-cookies_8390826
// https://www.geeksforgeeks.org/problems/assign-cookies/1
// https://leetcode.com/problems/assign-cookies/description/
// https://www.youtube.com/watch?v=DIX2p7vb9co

int assignCookie(vector<int> &greed, vector<int> &size) {
	int n = greed.size(), m = size.size();
	sort(greed.begin(), greed.end());
	sort(size.begin(), size.end());
	int l = 0, r = 0;
	while (l < n && r < m) {
		if (greed[l] <= size[r]) l++;
		r++;
	}
	return l;
}
