// https://www.naukri.com/code360/problems/remove-k-digits_1461221
// https://www.geeksforgeeks.org/problems/remove-k-digits/1
// https://leetcode.com/problems/remove-k-digits/description/
// https://www.youtube.com/watch?v=jmbuRzYPGrg

string removeKDigits(string num, int k) {
    int n = num.size();
    stack<char> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    if (st.empty()) return "0";
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    while (res.size() != 0 && res.back() == '0') res.pop_back();
    if (res.empty()) return "0";
    reverse(res.begin(), res.end());
    return res;
}
