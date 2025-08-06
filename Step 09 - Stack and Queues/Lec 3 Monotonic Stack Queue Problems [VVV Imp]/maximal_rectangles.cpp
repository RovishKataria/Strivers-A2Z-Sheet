// https://www.naukri.com/code360/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017
// https://www.geeksforgeeks.org/problems/max-rectangle/1
// https://leetcode.com/problems/maximal-rectangle/description/
// https://www.youtube.com/watch?v=ttVu6G7Ayik

#include<bits/stdc++.h>
int largestRectangle(vector<int>& heights, int n) {
	int max_area = 0;
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
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	if (mat.empty()) return 0;
	int max_area = 0;
	
	vector<vector<int>> prefix_sum(n, vector<int>(m));
	for (int j=0; j<m; j++) {
		int sum = 0;
		for (int i=0; i<n; i++) {
			sum += mat[i][j];
			if (mat[i][j] == 0) sum = 0;
			prefix_sum[i][j] = sum;
		}
	}

	for (int i=0; i<n; i++) {
		max_area = max(max_area, largestRectangle(prefix_sum[i], m));
	}
	return max_area;
}