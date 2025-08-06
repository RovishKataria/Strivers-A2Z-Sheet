// https://www.naukri.com/code360/problems/next-greater-element_10297924
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// https://www.youtube.com/watch?v=e7XQLtOQM3I

#include<bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n) {
	stack<int> st;
	vector<int> nge(n);
	for (int i=n-1; i>=0; i--) {
		while (!st.empty() && st.top() <= arr[i]) st.pop();
		if (st.empty()) nge[i] = -1;
		else nge[i] = st.top();
		st.push(arr[i]);
	}
	return nge;
}
