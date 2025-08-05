// https://www.naukri.com/code360/problems/prefix-to-infix_1215000
// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
// https://www.youtube.com/watch?v=4pIc9UBHJtk

string prefixToInfixConversion(string &s) {
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
            string str = '(' + s1 + s[i] + s2 + ')';
            st.push(str);
        }
        i--;
    }
    return st.top();
}
