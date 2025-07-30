// https://www.naukri.com/code360/problems/merge-all-overlapping-intervals_6783452
// https://www.naukri.com/code360/problems/merge-overlapping-intervals_1082151
// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1
// https://leetcode.com/problems/merge-intervals/description/
// https://www.youtube.com/watch?v=2JzRBPFYbKE

#include<vector>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>> merged_intevals;
	if (arr.size() == 0) return merged_intevals;
	sort(arr.begin(), arr.end());
	vector<int> temp_interval = arr[0];
	
	for (int i=0; i<arr.size(); i++) {
		if (arr[i][0] <= temp_interval[1]) {
			temp_interval[1] = max(arr[i][1], temp_interval[1]);
		} else {
			merged_intevals.push_back(temp_interval);
			temp_interval = arr[i];
		}
	}
	merged_intevals.push_back(temp_interval);
	return merged_intevals;
}