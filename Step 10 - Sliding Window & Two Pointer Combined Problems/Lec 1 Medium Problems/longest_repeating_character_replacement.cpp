// https://www.naukri.com/code360/problems/longest-repeating-substring_980523
// https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1
// https://leetcode.com/problems/longest-repeating-character-replacement/
// https://www.youtube.com/watch?v=_eNhaDCr6P0

int longestRepeatingSubstring(string &str, int k) {
    int l = 0, r = 0, maxlen = 0, maxfreq = 0, n = str.size();
    unordered_map<char, int> hash;
    while (r < n) {
        hash[str[r]]++;
        maxfreq = max(maxfreq, hash[str[r]]);
        if ((r-l+1) - maxfreq > k) {
            hash[str[l]]--;
            l++;
        } else maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}