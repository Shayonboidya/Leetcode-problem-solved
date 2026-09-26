class Solution {
public:
    bool ischar(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); 
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (ischar(s[i])) {
                res += s[i];
            } else {
                string temp = "";
                i++;
                while (i < n && s[i] != ')') {
                    temp += s[i];
                    i++;
                }
                if (mp.find(temp) == mp.end())
                    res += '?';
                else
                    res += mp[temp];
            }
        }
        return res;
    }
};