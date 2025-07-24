// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-iii_1071012
// https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
// https://www.youtube.com/watch?v=-uQGzhYj8BQ

// memoization
int f(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
    if (cap==0) return 0;
    if (ind==n) return 0;
    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    if (buy) {
        int take = -prices[ind] + f(ind+1, 0, cap, prices, n, dp);
        int not_take = 0 + f(ind+1, 1, cap, prices, n, dp);
        profit = max(take, not_take);
    }
    else {
        int take = prices[ind] + f(ind+1, 1, cap-1, prices, n, dp);
        int not_take = 0 + f(ind+1, 0, cap, prices, n, dp);
        profit = max(take, not_take);
    }
    return dp[ind][buy][cap] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    return f(0, 1, 2, prices, n, dp);
}

// tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    // writing base cases not mean anything as they are 0 already
    // for (int i=0; i<=n; i++) dp[i][0][0] = dp[i][1][0] = 0;
    // dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = 0;
    // dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 0;

    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            for (int cap=1; cap<=2; cap++) {
                int profit = 0;
                if (buy) {
                    int take = -prices[ind] + dp[ind+1][0][cap];
                    int not_take = 0 + dp[ind+1][1][cap];
                    profit = max(take, not_take);
                }
                else {
                    int take = prices[ind] + dp[ind+1][1][cap-1];
                    int not_take = 0 + dp[ind+1][0][cap];
                    profit = max(take, not_take);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

// optimized
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> front(2, vector<int> (3, 0)), curr(2, vector<int> (3, 0));

    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            for (int cap=1; cap<=2; cap++) {
                int profit = 0;
                if (buy) {
                    int take = -prices[ind] + front[0][cap];
                    int not_take = 0 + front[1][cap];
                    profit = max(take, not_take);
                }
                else {
                    int take = prices[ind] + front[1][cap-1];
                    int not_take = 0 + front[0][cap];
                    profit = max(take, not_take);
                }
                curr[buy][cap] = profit;
            }
        }
        front = curr;
    }
    return front[1][2];
}


// Another way for solving the problem
// memoization
int f(int ind, int trans, vector<int>& prices, int n, vector<vector<int>>& dp) {
    if (trans==4) return 0;
    if (ind==n) return 0;
    if (dp[ind][trans] != -1) dp[ind][trans];

    int profit = 0;
    if (trans % 2 == 0) {
        int take = -prices[ind] + f(ind+1, trans+1, prices, n, dp);
        int not_take = 0 + f(ind+1, trans, prices, n, dp);
        profit = max(take, not_take);
    }
    else {
        int take = prices[ind] + f(ind+1, trans+1, prices, n, dp);
        int not_take = 0 + f(ind+1, trans, prices, n, dp);
        profit = max(take, not_take);
    }
    return dp[ind][trans] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return f(0, 0, prices, n, dp);
}

// tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (4+1, 0));

    for (int ind=n-1; ind>=0; ind--) {
        for (int trans=3; trans>=0; trans--) {
            int profit = 0;
            if (trans % 2 == 0) {
                int take = -prices[ind] + dp[ind+1][trans+1];
                int not_take = 0 + dp[ind+1][trans];
                profit = max(take, not_take);
            }
            else {
                int take = prices[ind] + dp[ind+1][trans+1];
                int not_take = 0 + dp[ind+1][trans];
                profit = max(take, not_take);
            }
            dp[ind][trans] = profit;
        }
    }
    return dp[0][0];
}

// optimized
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> front(4+1, 0), curr(4+1, 0);

    for (int ind=n-1; ind>=0; ind--) {
        for (int trans=3; trans>=0; trans--) {
            int profit = 0;
            if (trans % 2 == 0) {
                int take = -prices[ind] + front[trans+1];
                int not_take = 0 + front[trans];
                profit = max(take, not_take);
            }
            else {
                int take = prices[ind] + front[trans+1];
                int not_take = 0 + front[trans];
                profit = max(take, not_take);
            }
            curr[trans] = profit;
        }
        front = curr;
    }
    return front[0];
}