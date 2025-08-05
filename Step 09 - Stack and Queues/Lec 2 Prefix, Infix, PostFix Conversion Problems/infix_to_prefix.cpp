// https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1
// https://www.youtube.com/watch?v=4pIc9UBHJtk

class Solution {
  private:
    int priority(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }
  public:
    string infixToPrefix(string s) {
        int i=0, n = s.size();
        stack<char> st;
        string ans = "";
        
        reverse(s.begin(), s.end());
        for (int j=0; j<n; j++) {
            if (s[j] == '(') s[j] = ')';
            else if (s[j] == ')') s[j] = '(';
        }
        
        while (i < n) {
            // if ((s[i] >= 'A' || s[i] <= 'Z') ||
            //     (s[i] >= 'a' || s[i] <= 'z') ||
            //     (s[i] >= '0' || s[i] <= '9')) {
            //     ans += s[i];
            if (isalnum(s[i])) {
                ans += s[i];
            } else if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && ((priority(s[i]) < priority(st.top())) ||
                    (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Solution fails: because we are building the output string ans += s[i] character by character — with potentially thousands of characters, this leads to:
// Inefficient memory reallocations.
// Performance bottlenecks.
// Potential overflows with large test cases (especially when reversing and copying strings multiple times).
// Also, if the expression has highly nested parentheses, code could be using the call stack (and STL stack) excessively.

// Fix:
// Used stringstream to avoid repeated string += char operations → much more memory-efficient.
// Added a safeguard for st.empty() before st.top() and st.pop().
// Overall time and space optimized for large inputs.

class Solution {
  private:
    int priority(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

  public:
    string infixToPrefix(string s) {
        int n = s.size();
        stack<char> st;
        stringstream ss;

        // Reverse and swap brackets
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }

        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                ss << s[i];
            } else if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ss << st.top(); st.pop();
                }
                if (!st.empty()) st.pop();
            } else {
                while (!st.empty() && (
                    priority(s[i]) < priority(st.top()) ||
                    (priority(s[i]) == priority(st.top()) && s[i] != '^')
                )) {
                    ss << st.top(); st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            ss << st.top(); st.pop();
        }

        string res = ss.str();
        reverse(res.begin(), res.end());
        return res;
    }
};
