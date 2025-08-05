// https://www.naukri.com/code360/problems/convert-prefix-to-postfix_8391014
// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1
// https://www.youtube.com/watch?v=4pIc9UBHJtk

string preToPost(string s) {
    int n = s.size();
    int i = n-1;
    stack<string> st;
    while (i >= 0) {
        if (isalnum(s[i])) {
            // convert char to string
            st.push(string(1, s[i]));
        } else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            st.push(s1 + s2 + s[i]);
        }
        i--;
    }
    return st.top();
}