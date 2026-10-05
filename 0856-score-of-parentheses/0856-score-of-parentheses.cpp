class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int score = 0;
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                d++;
            } else {
                d--;
                if(s[i-1] == '('){
                    score += 1 << d;
                }
            }
        }
        return score;
    }
};