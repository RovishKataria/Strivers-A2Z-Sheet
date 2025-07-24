// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_893405
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://www.geeksforgeeks.org/problems/buy-stock-2/1
// https://www.youtube.com/watch?v=excAOvwF_Wk

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini = prices[0], profit = 0;
    for (int i=1; i<prices.size(); i++) {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}