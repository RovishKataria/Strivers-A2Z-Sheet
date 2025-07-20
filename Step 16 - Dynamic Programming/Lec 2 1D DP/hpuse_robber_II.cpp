// https://www.naukri.com/code360/problems/house-robber_839733
// https://www.youtube.com/watch?v=3WaxQMELSkw

#include <bits/stdc++.h> 
long long int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    long long int prev = nums[0], prev2 = 0;
    
    for (int i=1; i<n; i++) {
        long long int pick = nums[i];
        if (i > 1) pick += prev2;
        long long int nonpick = 0 + prev;

        long long int curr = max(pick, nonpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
#include <bits/stdc++.h> 
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];

    vector<int> temp1, temp2;
    for (int i=0; i<n; i++) {
        if (i != 0) temp1.push_back(valueInHouse[i]);
        if (i != n-1) temp2.push_back(valueInHouse[i]);
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}
