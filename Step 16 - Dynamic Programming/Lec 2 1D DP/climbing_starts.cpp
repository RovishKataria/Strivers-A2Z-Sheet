// https://www.youtube.com/watch?v=mLfjzJsN8us
// https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650
#include <bits/stdc++.h> 
const int MOD = 1e9 + 7;
int countDistinctWays(int nStairs) {
    if (nStairs == 0 || nStairs == 1) return 1;
    int prev2 = 1, prev = 1, curr = 0;
    for (int i=2; i<=nStairs; i++) {
        curr = (prev2 + prev) % MOD;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
// https://leetcode.com/problems/climbing-stairs/description/
class Solution {
  public:
    int countWays(int n) {
        if (n == 0 || n == 1) return 1;
        int prev2 = 1, prev = 1, curr = 0;
        for (int i=2; i<=n; i++) {
            curr = (prev2 + prev);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};

