// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-ii_630282
// https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
// https://www.youtube.com/watch?v=excAOvwF_Wk

// memoization
#include<bits/stdc++.h>
long f(int ind, int buy, long *values, int n, vector<vector<long>>& dp) {
    if (ind == n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    long profit = 0;
    if (buy) {
        long take = -values[ind] + f(ind+1, 0, values, n, dp);
        long not_take = 0 + f(ind+1, 1, values, n, dp);
        profit = max(take, not_take);
    }
    else {
        long take = values[ind] + f(ind+1, 1, values, n, dp);
        long not_take = 0 + f(ind+1, 0, values, n, dp);
        profit = max(take, not_take);
    }
    return dp[ind][buy] = profit;
}
long getMaximumProfit(long *values, int n) {
    vector<vector<long>> dp(n, vector<long> (2, -1));
    return f(0, 1, values, n, dp);
}

// tabulation
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n) {
    vector<vector<long>> dp(n+1, vector<long> (2, 0));
    dp[n][0] = dp[n][1] = 0;
    
    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            long profit = 0;
            if (buy) {
                long take = -values[ind] + dp[ind+1][0];
                long not_take = 0 + dp[ind+1][1];
                profit = max(take, not_take);
            }
            else {
                long take = values[ind] + dp[ind+1][1];
                long not_take = 0 + dp[ind+1][0];
                profit = max(take, not_take);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// optimized
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n) {
    vector<long> front(2, 0), curr(2, 0);
    front[0] = front[1] = 0;
    
    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            long profit = 0;
            if (buy) {
                long take = -values[ind] + front[0];
                long not_take = 0 + front[1];
                profit = max(take, not_take);
            }
            else {
                long take = values[ind] + front[1];
                long not_take = 0 + front[0];
                profit = max(take, not_take);
            }
            curr[buy] = profit;
        }
        front = curr;
    }
    return front[1];
}

// four variables
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n) {
    long front_notbuy, front_buy, curr_notbuy, curr_buy;
    front_notbuy = front_buy = 0;
    
    for (int ind=n-1; ind>=0; ind--) {
        long take = -values[ind] + front_notbuy;
        long not_take = 0 + front_buy;
        curr_buy = max(take, not_take);

        take = values[ind] + front_buy;
        not_take = 0 + front_notbuy;
        curr_notbuy = max(take, not_take);

        front_notbuy = curr_notbuy;
        front_buy = curr_buy;
    }
    return front_buy;
}