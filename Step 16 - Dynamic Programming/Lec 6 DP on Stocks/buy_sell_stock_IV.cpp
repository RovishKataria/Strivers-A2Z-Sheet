// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_1080698
// https://www.geeksforgeeks.org/problems/maximum-profit4657/1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
// https://www.youtube.com/watch?v=IV1dHbk5CDc

// similar to part-III

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<int>> front(2, vector<int> (k+1, 0)), curr(2, vector<int> (k+1, 0));

    for (int ind=n-1; ind>=0; ind--) {
        for (int buy=0; buy<=1; buy++) {
            for (int cap=1; cap<=k; cap++) {
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
    return front[1][k];
}
