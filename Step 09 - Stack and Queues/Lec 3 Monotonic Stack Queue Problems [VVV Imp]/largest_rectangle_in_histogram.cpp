// https://www.naukri.com/code360/problems/largest-rectangle-in-a-histogram_1058184
// https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// https://www.youtube.com/watch?v=Bzat9vgD0fs

#include<bits/stdc++.h>
int largestRectangle(vector<int>& heights) {
	int n = heights.size(), max_area = 0;
	stack<int> st;
	for (int i=0; i<n; i++) {
		while (!st.empty() && heights[st.top()] > heights[i]) {
			int ind = st.top();
			st.pop();
			int pse = st.empty() ? -1 : st.top();
			int nse = i;
			max_area = max(max_area, heights[ind] * (nse - pse - 1));
		}
		st.push(i);
	}
	while (!st.empty()) {
		int ind = st.top();
		st.pop();
		int pse = st.empty() ? -1 : st.top();
		int nse = n;
		max_area = max(max_area, heights[ind] * (nse - pse - 1));
	}
	return max_area;
}