// https://www.naukri.com/code360/problems/subarrays-with-at-most-k-distinct-values_1473804
// https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/
// https://www.youtube.com/watch?v=7wYGbV_LsX4

int lessEq(vector<int> &arr, int n, int k) {
    int l = 0, r = 0, cnt = 0;
    unordered_map<int, int> umpp;
    while (r < n) {
        umpp[arr[r]]++;
        while (umpp.size() > k) {
            umpp[arr[l]]--;
            if (umpp[arr[l]] == 0) umpp.erase(arr[l]);
            l++;
        }
        cnt += (r-l+1);
        r++;
    }
    return cnt;
}
int kDistinctSubarrays(vector<int> &arr, int n, int k) {
    return lessEq(arr, n, k) - lessEq(arr, n, k-1);
}