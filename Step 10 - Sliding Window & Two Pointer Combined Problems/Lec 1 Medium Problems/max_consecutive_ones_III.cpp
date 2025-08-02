// https://www.naukri.com/code360/problems/maximum-consecutive-ones_892994
// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
// https://leetcode.com/problems/max-consecutive-ones-iii/description/
// https://www.youtube.com/watch?v=3E4JBHSLpYk

int longestSubSeg(vector<int> &arr , int n, int k){
    int l = 0, r = 0, maxlen = 0, zeros = 0;
    while (r < n) {
        if (arr[r] == 0) zeros++;
        if (zeros > k) {
            if (arr[l] == 0) zeros--;
            l++;
        }
        else maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}
