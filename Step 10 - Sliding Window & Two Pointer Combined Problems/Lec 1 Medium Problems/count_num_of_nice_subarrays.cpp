// https://www.naukri.com/code360/problems/count-distinct-subarrays-with-at-most-k-odd-elements_1069335
// https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// https://www.youtube.com/watch?v=j_QOv9OT9Og

int sumLessEqK(vector<int> &arr, int k) {
	if (k < 0) return 0;
	int l = 0, r = 0, cnt = 0, sum = 0, n = arr.size();
	while (r < n) {
		sum += (arr[r] % 2);
		while (sum > k) {
			sum -= (arr[l] % 2);
			l++;
		}
		cnt += (r-l+1);
		r++;
	}
	return cnt;
}
int distinctSubKOdds(vector<int> &arr, int k) {
	return sumLessEqK(arr, k) - sumLessEqK(arr, k-1);
}