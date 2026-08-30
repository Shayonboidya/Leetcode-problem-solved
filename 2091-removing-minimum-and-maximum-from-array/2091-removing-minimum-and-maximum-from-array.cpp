class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxElIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int minElIdx = min_element(nums.begin(), nums.end()) - nums.begin();

        int left = min (maxElIdx, minElIdx);
        int right = max (maxElIdx, minElIdx);
        return min({(left + 1 + n - right), right + 1, n-left});
    }
};