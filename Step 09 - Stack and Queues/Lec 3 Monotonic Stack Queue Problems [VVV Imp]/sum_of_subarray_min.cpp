// https://www.naukri.com/code360/problems/sum-of-subarray-minimums_8365431
// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1
// https://leetcode.com/problems/sum-of-subarray-minimums/description/
// https://www.youtube.com/watch?v=v0e8p9JCgRc

int mod = 1e9 + 7;
vector<int> findNSE(vector<int>& arr, int n) {
    vector<int> nse(n);
    stack<int> st;
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSEE(vector<int>& arr, int n) {
    vector<int> psee(n);
    stack<int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}
int sumSubarrayMins(vector<int>&arr) {
    int n = arr.size(), total = 0;
    vector<int> nse = findNSE(arr, n);
    vector<int> psee = findPSEE(arr, n);
    for (int i=0; i<n; i++) {
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }
    return total;
}