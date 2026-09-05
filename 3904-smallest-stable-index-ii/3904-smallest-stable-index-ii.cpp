class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int mx = INT_MIN;
        int mi = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (mx <= nums[i]) {
                mx = nums[i];
            }
            left[i] = mx;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (mi >= nums[i]) {
                mi = nums[i];
            }
            right[i] = mi;
        }
        for (int i = 0; i < n; i++) {
            int diff = left[i] - right[i];
            if (diff <= k) {
                return i;
            }
        }
        return -1;
    }
};