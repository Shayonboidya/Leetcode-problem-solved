class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int minSum = INT_MAX;

        for (int len = l; len <= r; len++) {

            for (int st = 0; st + len <= n; st++) {

                int end = st + len;

                int sum = pref[end] - pref[st];

                if (sum > 0) {
                    minSum = min(minSum, sum);
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};