// https://www.naukri.com/code360/problems/subarray-range-sum_8365419
// https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1
// https://leetcode.com/problems/sum-of-subarray-ranges/description/
// https://www.youtube.com/watch?v=gIrMptNPf5M

vector<int> findPGEE(vector<int>&arr, int n) {
    stack<int> st;
    vector<int> pgee(n);
    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
}
vector<int> findNGE(vector<int>&arr, int n) {
    stack<int> st;
    vector<int> nge(n);
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
}
int sumSubarrayMaxs(vector<int>&arr, int n) {
    int total = 0;
    vector<int> nge = findNGE(arr, n);
    vector<int> pgee = findPGEE(arr, n);
    for (int i=0; i<n; i++) {
        int left = i - pgee[i];
        int right = nge[i] - i;
        total += (1LL * left * right * arr[i]);
    }
    return total;
}
vector<int> findPSEE(vector<int>&arr, int n) {
    stack<int> st;
    vector<int> psee(n);
    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}
vector<int> findNSE(vector<int>&arr, int n) {
    stack<int> st;
    vector<int> nse(n);
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
int sumSubarrayMins(vector<int>&arr, int n) {
    int total = 0;
    vector<int> psee = findPSEE(arr, n);
    vector<int> nse = findNSE(arr, n);
    for (int i=0; i<n; i++) {
        int left = i - psee[i];
        int right = nse[i] - i;
        total += (1LL * left * right * arr[i]);
    }
    return total;
}
int rangeSum(vector<int>&nums) {
    int n = nums.size();
    return sumSubarrayMaxs(nums, n) - sumSubarrayMins(nums, n);
}