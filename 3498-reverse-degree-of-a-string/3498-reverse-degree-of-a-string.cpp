class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, cnt = 1;
        for(auto ch:s){
            int c = 'z' - ch + 1;
            ans += c * cnt;
            cnt++;
        }
        return ans;
    }
};