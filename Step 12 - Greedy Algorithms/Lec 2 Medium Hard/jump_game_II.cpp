// https://www.naukri.com/code360/problems/jump-game_893178
// https://www.naukri.com/code360/problems/jump-game_6212556
// https://leetcode.com/problems/jump-game-ii/description/
// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// memoization - but large space comlpexity
int f(int ind, int jumps, vector<int> &arr,int n, vector<vector<int>>& dp) {
    if (ind >= n-1) return jumps;
    if (dp[ind][jumps] != -1) return dp[ind][jumps];
    int mini = INT_MAX;
    for (int i=1; i<=arr[ind]; i++)
        mini = min(mini, f(ind+i, jumps+1, arr, n, dp));
    return dp[ind][jumps] = mini;
}
int minJumps(vector<int> &arr,int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int result = f(0, 0, arr, n, dp);
    return result == INT_MAX ? -1 : result;
}

// another optimization
int minJumps(vector<int> &arr, int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int jumps = 0, l = 0, r = 0;

    while (r < n - 1) {
        int farthest = 0;

        for (int i = l; i <= r; i++) {
            farthest = max(farthest, i + arr[i]);
        }

        if (farthest <= r) return -1; // Can't move forward from this range

        l = r + 1;
        r = farthest;
        jumps++;
    }

    return jumps;
}
