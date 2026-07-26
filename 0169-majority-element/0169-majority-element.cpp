class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int feq = 0, ans = 0;
        for(int i = 0; i < n;i++){
            if(feq == 0) ans = nums[i];

            if(ans == nums[i]) feq++;
            else feq--;
        }
        return ans;
    }
};