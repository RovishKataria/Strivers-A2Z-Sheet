// https://www.naukri.com/code360/problems/target-sum_4127362
// https://www.geeksforgeeks.org/problems/target-sum-1626326450/1
// https://leetcode.com/problems/target-sum/description/
// https://www.youtube.com/watch?v=b3GD8263-PQ
// similar to count_partitions_with_given_difference

#include <bits/stdc++.h> 
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);
	// below 4 lines i did and they work fine.
	// prev[0] = 1;
	// curr[0] = 1;
	// if (arr[0] <= k) prev[arr[0]] = 1;
	// if (arr[0] == 0) prev[0] = 2;

	// below 3 lines striver did
	if(arr[0] == 0) prev[0] = 2;
	else prev[0] = 1;
	// we added arr[0] != 0 because what if arr[0] == 0 then it will become 1
	if (arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

	for (int ind=1; ind<n; ind++) {
		for (int sum=0; sum<=k; sum++) {
			int not_take = prev[sum];
			int take = 0;
			if (arr[ind] <= sum) take = prev[sum-arr[ind]];
			curr[sum] = (not_take + take);
		}
		prev = curr;
	}
	return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int total_sum = 0;
    for (auto &it:arr) total_sum += it;
    if (total_sum - d < 0 || (total_sum - d) % 2) return 0;
    return findWays(arr, (total_sum - d)/2);
}
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
