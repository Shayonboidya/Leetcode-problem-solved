class Solution {
public:
    void helper(int n, int open, int close,vector<string> &ans, string &s ){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            helper(n,open+1, close, ans,s);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            helper(n, open, close+1, ans, s);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(n, 0,0,ans,s);
        return ans;
    }
};