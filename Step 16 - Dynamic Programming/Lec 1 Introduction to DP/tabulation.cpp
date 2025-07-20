// https://www.geeksforgeeks.org/problems/introduction-to-dp/1
// https://www.youtube.com/watch?v=tyB0ztf0DNY

#include "bits/stdc++.h"
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    // vector<int> dp(n+1, -1);
    // dp[0] = 0; dp[1] = 1;
    // for (int i=2; i<=n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout << dp[n];
    int prev2 = 0, prev = 1;
    for (int i=2; i<=n; i++) {
        int curri = prev2 + prev;
        prev2 = prev;
        prev = curri;
    }
    cout << prev;
    return 0;
}