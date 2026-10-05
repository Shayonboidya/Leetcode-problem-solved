class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int score = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                res.push_back(score);
                score = 0;
            } else {
                if ( s[i - 1] == '(') {
                    score = res.back() + 1;
                } else {
                    score = res.back() +  (score * 2);
                }
                res.pop_back();
            }
        }
        return score;
    }
};