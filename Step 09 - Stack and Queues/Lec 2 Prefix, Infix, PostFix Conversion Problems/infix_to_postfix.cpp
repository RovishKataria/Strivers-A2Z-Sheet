// https://www.naukri.com/code360/problems/day-23-:-infix-to-postfix-_1382146
// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// https://www.youtube.com/watch?v=4pIc9UBHJtk

#include<bits/stdc++.h>
int priority(char op) {
	if (op == '^') return 3;
	else if (op == '*' || op == '/') return 2;
	else if (op == '+' || op == '-') return 1;
	return -1;
}
string infixToPostfix(string exp) {
	int i = 0, n = exp.size();
	string ans = "";
	stack<char> st;
	while (i < n) {
		if ((exp[i] >= 'A' && exp[i] <= 'Z') ||
			(exp[i] >= 'a' && exp[i] <= 'z') ||
			(exp[i] >= '0' && exp[i] <= '9')) {
			ans += exp[i];
		} else if (exp[i] == '(') {
			st.push(exp[i]);
		} else if (exp[i] == ')') {
			// adding stack.top() until '(' reached
			while (!st.empty() && st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.pop(); //poping '(' from stack
		} else {
			while (!st.empty() && priority(exp[i]) <= priority(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
		i++;
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	return ans;
}