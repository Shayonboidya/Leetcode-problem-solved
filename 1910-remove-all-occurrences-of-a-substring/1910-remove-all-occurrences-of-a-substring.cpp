class Solution {
public:
    string removeOccurrences(string s, string part) {
        // // while(s.length() > 0 && s.find(part) < s.length()){
        // //     s.erase(s.find(part),part.length());
        // // }

        // string ans;
        // for(char ch:s){
        //     ans.push_back(ch);
        //     if(ans.size() >= part.size()){
        //         if(ans.substr(ans.size() - part.size()) == part){
        //             ans.erase(ans.size() - part.size());
        //         }
        //     }
        // }
        // // return s;
        // return ans;
        while(s.find(part) != string::npos){
            s.erase(s.find(part),part.size());
        }
        return s;

    }
};