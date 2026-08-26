class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        for (int len = k; len <= n; len++) {
            string res = "";
            for (int st = 0; st <= n - len; st++) {
                string temp = s.substr(st, len);
                int one = 0;
                for (char& ch : temp) {
                    one += (ch == '1') ? 1 : 0;
                }
                if (one == k) {
                    if (res.empty() || temp < res)
                        res = temp;
                }
            }
            if (!res.empty()) {
                return res;
            }
        }
        return "";
    }
};