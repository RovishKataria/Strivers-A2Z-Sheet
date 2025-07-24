// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-with-cooldown_3125969
// https://www.geeksforgeeks.org/problems/buy-stock-with-cooldown/1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
// https://www.youtube.com/watch?v=IGIe46xw3YY

// similar to part-II

// memoization
int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>>& dp) {
    if (ind >= n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if (buy) {
        int take = -prices[ind] + f(ind+1, 0, prices, n, dp);
        int not_take = 0 + f(ind+1, 1, prices, n, dp);
        profit = max(take, not_take);
    }
    else {
        int take = prices[ind] + f(ind+2, 1, prices, n, dp);
        int not_take = 0 + f(ind+1, 0, prices, n, dp);
        profit = max(take, not_take);
    }
    return dp[ind][buy] = profit;
}
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return f(0, 1, prices, n, dp);
}

// tabulation
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int> (2, 0));
    
    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            int profit = 0;
            if (buy) {
                int take = -prices[ind] + dp[ind+1][0];
                int not_take = 0 + dp[ind+1][1];
                profit = max(take, not_take);
            }
            else {
                int take = prices[ind] + dp[ind+2][1];
                int not_take = 0 + dp[ind+1][0];
                profit = max(take, not_take);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// optimized - we will optimize this beacause it has ind+1 and ind+2 so, we need to create 3 diff arrays
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<int> front1(2, 0), front2(2, 0), curr(2, 0);
    
    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            int profit = 0;
            if (buy) {
                int take = -prices[ind] + front1[0];
                int not_take = 0 + front1[1];
                profit = max(take, not_take);
            }
            else {
                int take = prices[ind] + front2[1];
                int not_take = 0 + front1[0];
                profit = max(take, not_take);
            }
            curr[buy] = profit;
        }
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}