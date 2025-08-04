// https://www.naukri.com/code360/problems/min-stack_3843991
// https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// https://leetcode.com/problems/min-stack/description/
// https://www.youtube.com/watch?v=NdDIaH91P0g

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack {
	stack<int> st;
	int mini;
	
	public:
		
		// Constructor
		minStack() {
			mini = -1;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num) {
			if (st.empty()) {
				st.push(num);
				mini = num;
			} else {
				if (num > mini) st.push(num);
				else {
					st.push(2*num - mini);
					mini = num;
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop() {
			if (st.empty()) return -1;
			int elem = st.top();
			st.pop();
			if (elem < mini) {
				int el = mini;
				mini = 2*mini - elem;
				return el;
			}
			return elem;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top() {
			if (st.empty()) return -1;
			int elem = st.top();
			if (mini < elem) return elem;
			return mini;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin() {
			if (st.empty()) return -1;
			return mini;
		}
};