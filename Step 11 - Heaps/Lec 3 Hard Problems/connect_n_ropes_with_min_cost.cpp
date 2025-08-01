// https://www.naukri.com/code360/problems/connect-n-ropes-with-minimum-cost_625783
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include<bits/stdc++.h>
int minCost(int arr[], int n) {
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for (int i=0; i<n; i++) min_heap.push(arr[i]);

	int cost = 0;
	while (min_heap.size() > 1) {
		int rope1 = min_heap.top(); min_heap.pop();
		int rope2 = min_heap.top(); min_heap.pop();
		cost += (rope1 + rope2);
		min_heap.push(rope1 + rope2);
	}
	return cost;
}
