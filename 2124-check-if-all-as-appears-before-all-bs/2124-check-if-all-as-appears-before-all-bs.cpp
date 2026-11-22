class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i < n && s[i] == 'b' && s[i + 1] == 'a') {
                return false;
            }
        }
        return true;
    }
};