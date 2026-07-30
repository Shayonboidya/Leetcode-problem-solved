class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), ans = 0;
        int cnt = 0;
        while(n >= 8){
            n -= 8;
            cnt++;
            ans += 8 * cnt;
        }
        ans += n * (cnt+1);
        
        return ans;
    }
};