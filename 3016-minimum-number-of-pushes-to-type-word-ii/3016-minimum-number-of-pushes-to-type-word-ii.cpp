class Solution {
public:
    int minimumPushes(string word) {

        int n = word.length(), ans = 0;
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++) {
            mp[word[i] - 'a']++;
        }
        sort(mp.begin(), mp.end(), greater<int>());
        for (int i = 0; i < 26; i++) {
            int par = (i / 8) + 1;
            ans += mp[i] * par;
        }
        return ans;
    }
};