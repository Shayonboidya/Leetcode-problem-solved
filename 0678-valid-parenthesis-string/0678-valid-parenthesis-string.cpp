class Solution {
public:
    int t[101][101];
    bool solved(string s, int i, int st, int n) {
        if (i == n) {
            return st == 0;
        }
        if (t[i][st] != -1) {
            return t[i][st];
        }

        bool isValid = false;
        if (s[i] == '(') {
            isValid |= solved(s, i + 1, st + 1, n);
        } else if (s[i] == ')') {
            if (st > 0) {
                isValid |= solved(s, i + 1, st - 1, n);
            }
        } else {
            isValid |= solved(s, i + 1, st + 1, n);
            isValid |= solved(s, i + 1, st, n);
            if (st > 0) {
                isValid |= solved(s, i + 1, st - 1, n);
            }
        }
        return t[i][st] = isValid;
    }
    bool checkValidString(string s) { 
        memset(t,-1,sizeof(t));
        return solved(s, 0, 0, s.length()); }
};