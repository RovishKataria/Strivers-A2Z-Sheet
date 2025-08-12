// https://www.naukri.com/code360/problems/power-set_1062667
// https://www.geeksforgeeks.org/problems/subsets-1613027340/1
// https://leetcode.com/problems/subsets/description/
// https://www.youtube.com/watch?v=LqKaUv1G3_I

#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v) {
    int n = v.size();
    int subsets = 1<<n;
    vector<vector<int>> ans;
    for (int num=0; num<subsets; num++) {
        vector<int> lis;
        for (int i=0; i<n; i++) {
            if (num & (1 << i)) lis.push_back(v[i]);
        }
        ans.push_back(lis);
    }
    return ans;
}