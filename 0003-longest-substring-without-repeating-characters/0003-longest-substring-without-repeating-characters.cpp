class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left =0, max_len = 0;
        unordered_set<char>set;
        for(int right =0; right < s.size();right++){
            while(set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            max_len = max(max_len, right-left+1);
        }
        return max_len;
    }
};