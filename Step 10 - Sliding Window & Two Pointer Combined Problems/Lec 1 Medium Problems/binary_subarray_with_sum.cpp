// https://www.naukri.com/code360/problems/count-substrings-with-k-ones_3128698
// https://www.geeksforgeeks.org/problems/binary-subarray-with-sum/1
// https://leetcode.com/problems/binary-subarrays-with-sum/description/
// https://www.youtube.com/watch?v=XnMdNUkX6VM

int sumLessEqK(vector<int> &arr, int k) {
    if (k < 0) return 0;
    int l = 0, r = 0, cnt = 0, sum = 0, n = arr.size();
    while (r < n) {
        sum += arr[r];
        while (sum > k) {
            sum -= arr[l];
            l++;
        }
        cnt += (r-l+1);
        r++;
    }
    return cnt;
}
int subarrayWithSum(vector<int> &arr, int k) {
    return sumLessEqK(arr, k) - sumLessEqK(arr, k-1);
}