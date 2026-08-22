class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int>a;
        unordered_map<int,int>mp;
        /*overall O(v.size())*/
        for(int i = 0; i< v.size();i++){
            int first = v[i];
            int sec = target - first;

            if(mp.find(sec) != mp.end()){//TC -> O(1)
                a.push_back(i);
                a.push_back(mp[sec]);
                break;
            }
            mp[first] = i;
        }
        return a;
        
    }
};