class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto s: strs){
            vector<int> v(26,0);
            for(auto c:s){
                v[c-'a']++;
            }
            string key;
            for(auto x:v){
                key += '#' + to_string(x);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;

    }
};