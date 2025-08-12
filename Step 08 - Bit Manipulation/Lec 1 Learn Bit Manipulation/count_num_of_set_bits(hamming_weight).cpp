// https://www.geeksforgeeks.org/problems/set-bits0143/1
// https://leetcode.com/problems/number-of-1-bits/description/
// https://www.youtube.com/watch?v=nttpF8kwgd4

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n != 0) {
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
