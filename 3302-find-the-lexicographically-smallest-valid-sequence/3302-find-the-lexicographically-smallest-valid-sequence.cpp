class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> rightHandSideMatchChart(n, 0);
        int cnt = 0, i = n - 1, j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                cnt++;
                j--;
            }
            rightHandSideMatchChart[i] = cnt;
            i--;
        }
        vector<int> ans;
        bool ischange = false;
        i = 0, j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!ischange && i + 1 < n &&
                       rightHandSideMatchChart[i + 1] >= m - j - 1) {
                ans.push_back(i);
                ischange = true;
                j++;
            }
            i++;
        }
        return j == m ? ans : vector<int>();
    }
};