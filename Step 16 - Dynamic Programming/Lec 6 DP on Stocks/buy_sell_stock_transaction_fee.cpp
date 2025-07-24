// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-with-transaction-fee_3118974
// https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// https://www.youtube.com/watch?v=k4eK-vEmnKg

// similar to part-II

int maximumProfit(vector<int> &prices, int n, int fee) {
    int front_notbuy, front_buy, curr_notbuy, curr_buy;
    front_notbuy = front_buy = 0;
    
    for (int ind=n-1; ind>=0; ind--) {
        int take = -prices[ind] + front_notbuy;
        int not_take = 0 + front_buy;
        curr_buy = max(take, not_take);

        take = prices[ind] - fee + front_buy;
        not_take = 0 + front_notbuy;
        curr_notbuy = max(take, not_take);

        front_notbuy = curr_notbuy;
        front_buy = curr_buy;
    }
    return front_buy;
}
