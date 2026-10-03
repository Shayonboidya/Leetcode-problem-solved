class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                open++;
            } else {
                close++;
            }
            if (close > open) {
                close = 0;
                open = 0;
            } else if (open == close) {
                res = max(res, open + close);
            }
        }
        open = 0;
        close = 0;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '(') {
                open++;
            } else {
                close++;
            }

            if (open > close) {
                close = 0;
                open = 0;
            } else if (open == close) {
                res = max(res, open + close);
            }
        }
        return res;
    }
};