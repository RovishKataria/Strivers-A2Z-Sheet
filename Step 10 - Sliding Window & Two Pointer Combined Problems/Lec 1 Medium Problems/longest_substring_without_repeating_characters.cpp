// https://www.naukri.com/code360/problems/longest-unique-substring_630418
// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// https://www.youtube.com/watch?v=-zSxTJkcdAo

#include <bits/stdc++.h> 
int uniqueSubstrings(string input) {
    int n = input.size();
    int l = 0, r = 0, maxlen = 0;
    vector<int> hash(256, -1);
    while (r < n) {
        if (hash[input[r]] != -1) {
            if (hash[input[r]] >= l) l = hash[input[r]] + 1;
        }
        maxlen = max(maxlen, r-l+1);
        hash[input[r]] = r;
        r++;
    }
    return maxlen;
}