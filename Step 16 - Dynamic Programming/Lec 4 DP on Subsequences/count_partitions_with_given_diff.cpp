// https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// https://www.youtube.com/watch?v=zoilQD1kYSg
// similar to count_subset_with_sum_k

#include <bits/stdc++.h> 
const int mod = 1e9 + 7;
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
			curr[sum] = (not_take + take) % mod;
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
