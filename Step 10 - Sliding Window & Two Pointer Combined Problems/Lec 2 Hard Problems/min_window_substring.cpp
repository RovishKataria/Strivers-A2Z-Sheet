// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// https://leetcode.com/problems/minimum-window-substring/description/
// https://www.youtube.com/watch?v=WJaij9ffOIY

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int l = 0, r = 0, cnt = 0, sind = -1, minlen = 1e9;
        vector<int> hash(256, 0);
        for (int i=0; i<m; i++) hash[t[i]]++;
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while (cnt == m) {
                if (r-l+1 < minlen) {
                    minlen = r-l+1;
                    sind = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (sind == -1 ? "" : s.substr(sind, minlen));
    }
};
