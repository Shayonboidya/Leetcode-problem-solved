class Solution {
public:
    int n;
    int maxLen;
    unordered_set<string> st;

    void solved(string& s, string &str, int i, int cnt) {
        if (cnt < 0)
            return;
        if (i == n) {
            if (cnt == 0) {
                if (maxLen < str.length()) {
                    st.clear();
                    maxLen = str.length();
                }
                if (maxLen == str.length()) {
                    st.insert(str);
                }
            }
            return;
        }
        if (s[i] != '(' && s[i] != ')') {
            str.push_back(s[i]);
            solved(s, str, i + 1, cnt);
            str.pop_back();
            return;
        }
        str.push_back(s[i]);
        solved(s, str, i + 1, cnt + (s[i] == '(' ? 1 : -1));
        str.pop_back();
        solved(s, str, i + 1, cnt);
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        st.clear();
        n = s.length();
        maxLen = 0;
        string str = "";
        solved(s, str, 0,0);
        return vector<string>(st.begin(), st.end());
    }
};