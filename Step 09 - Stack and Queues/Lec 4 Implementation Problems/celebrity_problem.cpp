// https://www.naukri.com/code360/problems/the-celebrity-problem_10728328
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
// https://leetcode.com/problems/find-the-celebrity/description/
// https://www.youtube.com/watch?v=cEadsbTeze4

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	int top = 0, down = n-1;
	while (top < down) {
		if (knows(top, down)) top++;
		else down--;
	}
	if (top > down) return -1;
	for (int i=0; i<n; i++) {
		if (i == top) continue;
		if (knows(top, i) == false && knows(i, top) == true) continue;
		else return -1;
	}
	return top;
}

// GFG
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
     	int top = 0, down = n-1;
    	while (top < down) {
    		if (mat[top][down]) top++;
    		else down--;
    	}
    	if (top > down) return -1;
    	for (int i=0; i<n; i++) {
    		if (i == top) continue;
    		if (mat[top][i] == false && mat[i][top] == true) continue;
    		else return -1;
    	}
    	return top;
    }
};