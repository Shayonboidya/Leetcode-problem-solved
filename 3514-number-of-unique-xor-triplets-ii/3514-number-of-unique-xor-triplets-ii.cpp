class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int t = 1, mx = *max_element(nums.begin(), nums.end());
        while (t <= mx) {
            t *= 2;
        }

        // pair xor
        vector<bool> s1(t, false);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (!s1[nums[i]^nums[j]]) {
                    s1[nums[i]^nums[j]] = true;
                }
            }
        }
        // triplet xor
        vector<bool> s2(t, false);
        for (int i = 0; i < t; i++) {
            if (s1[i]) {
                for (int& num : nums) {
                    if(!s2[i ^ num]){
                        s2[i ^ num] = true;
                    }
                }
            }
        }
        int ans = 0;
        for(int i =0;i < t;i++){
            if(s2[i])ans++;
        }
        return ans;
    }
};