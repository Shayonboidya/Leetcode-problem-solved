class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, max_cnt = 0;
        for( int i =0;i < s.length();i++){
            if(s[i] == '('){
                cnt++;
                max_cnt = max(max_cnt,cnt);
            }else if(s[i] == ')'){
                cnt--;
                max_cnt = max(max_cnt,cnt);
            }
        }
        return max_cnt;
    }
};