// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
// https://www.interviewbit.com/problems/nearest-smaller-element/
// https://www.youtube.com/watch?v=zMdbdGJNlh4

class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i=0; i<n; i++) {
            while (!st.empty() && st.top() >= arr[i]) st.pop();
            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};