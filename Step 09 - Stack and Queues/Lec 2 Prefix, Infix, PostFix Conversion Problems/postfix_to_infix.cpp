// https://www.naukri.com/code360/problems/postfix-to-infix_8382386
// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1
// https://www.youtube.com/watch?v=4pIc9UBHJtk

#include<bits/stdc++.h>
string postToInfix(string postfix) {
    int i = 0, n = postfix.size();
    stack<string> st;
    while (i < n) {
        if (isalnum(postfix[i])) {
            // convert char to string
            st.push(string(1, postfix[i]));
        } else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string s = '(' + s2 + postfix[i] + s1 + ')';
            st.push(s);
        }
        i++;
    }
    return st.top();
}