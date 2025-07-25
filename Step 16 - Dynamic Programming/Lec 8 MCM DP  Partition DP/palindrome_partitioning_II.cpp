// https://www.naukri.com/code360/problems/palindrome-partitioning-ll_873266
// https://leetcode.com/problems/palindrome-partitioning-ii/description/
// https://www.youtube.com/watch?v=_H8V5hJUGd0

// memoization
bool isPalindrome(int i, int j, string s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, string s, int n, vector<int> &dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int minCost = INT_MAX;
    for (int j=i; j<n; j++) {
        if (isPalindrome(i, j, s)) {
            int cost = 1 + f(j+1, s, n, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int palindromePartitioning(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return f(0, s, n, dp) - 1;
}

// tabulation
bool isPalindrome(int i, int j, string s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);

    for (int i=n-1; i>=0; i--) {
        int minCost = INT_MAX;
        for (int j=i; j<n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

// for leetcode submission
// precompute the palindrome in an array