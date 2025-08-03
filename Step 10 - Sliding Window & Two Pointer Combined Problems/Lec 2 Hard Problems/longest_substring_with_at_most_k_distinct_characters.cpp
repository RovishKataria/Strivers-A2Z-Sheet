// https://www.naukri.com/code360/problems/distinct-characters_2221410
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
// https://www.youtube.com/watch?v=teM9ZsVRQyc

#include<bits/stdc++.h>
int kDistinctChars(int k, string &str) {
    int l = 0, r = 0, maxlen = 0, n = str.size();
    unordered_map<char, int> umpp;
    while (r < n) {
        umpp[str[r]]++;
        if (umpp.size() > k) {
            umpp[str[l]]--;
            if (umpp[str[l]] == 0) umpp.erase(str[l]);
            l++;
        } else maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}