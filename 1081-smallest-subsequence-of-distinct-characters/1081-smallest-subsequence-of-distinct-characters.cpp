class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastIdx(26, 0);
        vector<bool>taken(26,false);
        for(int i =0;i < n;i++){
            char ch = s[i];
            lastIdx[ch - 'a'] = i;
        }
        string res;
        for(int i = 0; i < n;i++){
            char ch = s[i];
            int idx = ch -'a';
            if(taken[idx] == true){
                continue;
            }

            while(!res.empty() && res.back() > ch && lastIdx[res.back()-'a'] > i){
                taken[res.back()-'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            taken[ch - 'a'] = true;
        }
        return res;
    }
};