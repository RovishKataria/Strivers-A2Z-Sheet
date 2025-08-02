// https://www.naukri.com/code360/problems/fruits-and-baskets_985356
// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
// https://leetcode.com/problems/fruit-into-baskets/description/
// https://www.youtube.com/watch?v=e3bs0uA1NhQ

int findMaxFruits(vector<int> &arr, int n) {
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> umpp;
    while (r < n) {
        umpp[arr[r]]++;
        if (umpp.size() > 2) {
            umpp[arr[l]]--;
            if (umpp[arr[l]] == 0) umpp.erase(arr[l]);
            l++;
        } else maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}