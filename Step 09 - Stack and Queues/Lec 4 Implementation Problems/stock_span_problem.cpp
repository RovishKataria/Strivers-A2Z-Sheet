// https://www.naukri.com/code360/problems/stock-span_99652
// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// https://leetcode.com/problems/online-stock-span/description/
// https://www.youtube.com/watch?v=eay-zoSRkVc

class StockSpanner {
    int ind;
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        ind = -1;
        st = stack<pair<int, int>>();
    }
    
    int next(int price) {
        ind++;
        while (!st.empty() && st.top().first <= price) st.pop();
        int span = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return span;
    }
};