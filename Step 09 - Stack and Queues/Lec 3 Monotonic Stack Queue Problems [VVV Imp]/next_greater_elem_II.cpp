// https://www.naukri.com/code360/problems/next-greater-element-ii_6212757
// https://www.geeksforgeeks.org/problems/next-greater-element/1
// https://leetcode.com/problems/next-greater-element-ii/description/
// https://www.youtube.com/watch?v=7PrncD7v9YQ

#include<bits/stdc++.h>
vector<int> nextGreaterElementII(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);
    for (int i=2*n-1; i>=0; i--) {
        while (!st.empty() && st.top() <= arr[i%n]) st.pop();
        if (i < n) nge[i] = st.empty() ? -1 : st.top();
        st.push(arr[i%n]);
    }
    return nge;
}
