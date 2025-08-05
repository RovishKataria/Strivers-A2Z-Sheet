// https://www.naukri.com/code360/problems/postfix-to-prefix_1788455
// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1
// https://www.youtube.com/watch?v=4pIc9UBHJtk

#include<bits/stdc++.h>
string postfixToPrefix(string &s) {
    int i = 0, n = s.size();
    stack<string> st;
    while (i < n) {
        if (isalnum(s[i])) {
            // convert char to string
            st.push(string(1, s[i]));
        } else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            st.push(s[i] + s2 + s1);
        }
        i++;
    }
    return st.top();
}