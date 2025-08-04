// https://www.naukri.com/code360/problems/valid-parenthesis_795104
// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
// https://leetcode.com/problems/valid-parentheses/description/
// https://www.youtube.com/watch?v=xwjS0iZhw4I

bool isValidParenthesis(string s) {
    stack<int> st;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (st.empty()) return false;
            char ch = st.top();
            st.pop();
            if ((s[i] == ')' && ch == '(') ||
                (s[i] == '}' && ch == '{') ||
                (s[i] == ']' && ch == '[')) {
                    continue;
            } else return false;
        }
    }
    return st.empty();
}