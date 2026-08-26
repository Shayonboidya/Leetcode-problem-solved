class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0, j = 0, one = 0;
        string res = "";
        while (j < n) {
            if (s[j] == '1') {
                one++;
            }
            while (s[i] == '0' || one > k) {
                if (s[i] == '1') {
                    one--;
                }
                i++;
            }
            if (one == k) {
                string temp = s.substr(i, j - i + 1);
                if (res.empty() || res.length() > j - i + 1 ||
                    (res.length() == j - i + 1 && res > temp)) {
                    res = temp;
                }
            }
            j++;
        }
        return res;
    }
};