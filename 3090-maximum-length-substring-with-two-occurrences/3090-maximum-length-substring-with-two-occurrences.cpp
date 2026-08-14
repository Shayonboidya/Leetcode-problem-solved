class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int mxLen = 0, l = 0;
        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;
            while (freq[s[r] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }
            mxLen = max(mxLen, r - l + 1);
        }
        return mxLen;
    }
};