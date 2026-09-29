class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length(), len = 0;
        stack<int> st;
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(len);
            }
            // int start = -1;
            else if (s[i] == ')') {
                // start = st.top();
                reverse(res.begin() + st.top(), res.begin() + len);
                st.pop();
            }else{
                res += s[i];
                len++;

            }
        }
        return res;
    }
};