class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int st = nums[0];
        int end = nums[n - 1];
        int cnt = st, i = 0;
        while (i < n) {
            if (nums[i] == cnt) {
                i++, cnt++;
            } else {
                ans.push_back(cnt);
                cnt++;
            }
        }
        return ans;
    }
};