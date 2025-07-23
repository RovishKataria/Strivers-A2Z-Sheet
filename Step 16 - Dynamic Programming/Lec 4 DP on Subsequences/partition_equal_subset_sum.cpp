// https://www.naukri.com/code360/problems/partition-equal-subset-sum-_892980
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
// https://leetcode.com/problems/partition-equal-subset-sum/
// https://www.youtube.com/watch?v=7win3dcgo3k
// similar to subset_sum_eq_to_target

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int ind=1; ind<n; ind++) {
        for (int target=1; target<=k; target++) {
            bool not_take = prev[target];
            bool take = false;
            if (arr[ind] <= target) take = prev[target-arr[ind]];
            
            curr[target] = take | not_take;
        }
        prev = curr;
    }
    return prev[k];
}
bool canPartition(vector<int> &arr, int n)
{
	int total_sum = 0;
	for (int i=0; i<n; i++) total_sum += arr[i];

	if (total_sum % 2) return false;
	int target = total_sum / 2;
	return subsetSumToK(n, target, arr);
}
