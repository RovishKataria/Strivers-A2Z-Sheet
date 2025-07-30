// https://www.naukri.com/code360/problems/fractional-knapsack_975286
// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// https://www.youtube.com/watch?v=1ibsQrnuEEg

#include <bits/stdc++.h> 
bool comp(pair<int, int> val1, pair<int, int> val2) {
    return (val1.second * val2.first >= val2.second * val1.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w) {
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);
    double total_value = 0;
    for (int i=0; i<n; i++) {
        if (items[i].first <= w) {
            total_value += items[i].second;
            w -= items[i].first;
        } else {
            total_value += (double)items[i].second * w / items[i].first;
            break;
        }
    }
    return total_value;
}