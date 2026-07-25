class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int l = s.size();
        int ans = 0;
        if(l < 2){
            ans = s[0]-'0';
            return ans;
        }
        int a = s[l-1]-'0', b = s[l-2] - '0';
        return a * b;
    }
};