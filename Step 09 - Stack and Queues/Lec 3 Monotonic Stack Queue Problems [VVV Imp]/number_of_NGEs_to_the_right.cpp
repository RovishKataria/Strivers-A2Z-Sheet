// https://www.naukri.com/code360/problems/count-of-greater-elements-to-the-right_8365436
// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    int n = arr.size(), m = query.size();
    vector<int> ans(m);
    for (int i=0; i<m; i++) {
        int cnt = 0;
        for (int j=query[i] + 1; j<n; j++) {
            if (arr[j] > arr[query[i]]) cnt++;
        }
        ans[i] = cnt;
    }
    return ans;
}