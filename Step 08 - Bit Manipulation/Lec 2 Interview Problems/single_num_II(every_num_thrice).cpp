// https://www.naukri.com/code360/problems/element-that-appears-once_1092888
// https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
// https://leetcode.com/problems/single-number-ii/
// https://www.youtube.com/watch?v=5Bb2nqA40JY

// better
int elementThatAppearsOnce(vector<int> arr) {
	int n = arr.size();
	int ans = 0;
	for (int bit_ind = 0; bit_ind<31; bit_ind++) {
		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (arr[i] & (1 << bit_ind)) cnt++;
		}
		if (cnt % 3 == 1) ans = ans | (1 << bit_ind);
	}
	return ans;
}

// optimal
int elementThatAppearsOnce(vector<int> arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	for (int i=1; i<n; i+=3) {
		if (arr[i] != arr[i-1]) return arr[i-1];
	}
	return arr[n-1];
}

// optimal-1 (remember)
int elementThatAppearsOnce(vector<int> arr) {
	int n = arr.size();
	int ones = 0, twos = 0;
	for (int i=0; i<n; i++) {
		ones = (ones ^ arr[i]) & ~twos;
		twos = (twos ^ arr[i]) & ~ones;
	}
	return ones;
}