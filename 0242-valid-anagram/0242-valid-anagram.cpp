class Solution {
public:
    bool isT(vector<int>&f1, vector<int>&f2){
        for(int i =0 ;i < 26;i++){
            if(f1[i] != f2[i]){
                return false;
                break;
            }
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        vector<int>f1(26,0);
        vector<int>f2(26,0);

        for(auto c:s){
            f1[c-'a']++;
        }
        for(auto ch:t){
            f2[ch-'a']++;
        }
        return isT(f1,f2);

    }
};