class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());

        int i = 1;
        while(true){
            if(set.find(i*k) == set.end()){
                return k*i;
            }
            i++;
        }
        return k;
    }
};