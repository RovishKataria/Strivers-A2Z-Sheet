// https://www.naukri.com/code360/problems/count-substring-with-abc_8160465
// https://www.geeksforgeeks.org/problems/count-substring/1
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
// https://www.youtube.com/watch?v=xtqN4qlgr8s

int countSubstring(string s) {
    int cnt = 0, n = s.size();
    vector<int> lastseen(3, -1);
    for (int i=0; i<n; i++) {
        lastseen[s[i] - 'a'] = i;
        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[1] != -1)
            cnt += (1 + min(lastseen[0], min(lastseen[1], lastseen[2])));
    }
    return cnt;
}