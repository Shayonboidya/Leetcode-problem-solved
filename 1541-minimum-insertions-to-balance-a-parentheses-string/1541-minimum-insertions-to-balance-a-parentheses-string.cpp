class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int ans = 0;

        int cnt = 0, i = 0;
        while (i < n) {
            if (s[i] == '(') {
                cnt++;
                i++;
            } else {
                if (cnt > 0) {
                    cnt--;
                } else {
                    ans += 1;
                }
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    ans += 1;
                    i++;
                }
            }
        }
        return (cnt != 0) ? ans + cnt * 2 : ans;
    }
};