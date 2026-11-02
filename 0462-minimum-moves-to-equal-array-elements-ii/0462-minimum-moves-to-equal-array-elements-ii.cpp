class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        sort(nums.begin(), nums.end());

        int mid = nums[n / 2];
        for (int i = 0; i < n / 2; i++) {
            ans += abs(mid - nums[i]);
            ans += abs(mid - nums[n - i - 1]);
        }
        return ans;
    }
};