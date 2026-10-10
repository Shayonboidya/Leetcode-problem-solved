class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<long long> vec(1e5 + 1, 0);
        for (int i = 0; i < n; i++) {
            long long diff = (long long)abs(nums1[i] - nums2[i]);
            vec[diff]++;
        }

        long long k = k1 + k2;

        for (int i = 1e5; i > 0 && k > 0; i--) {
            int diffmin = min(vec[i], k);
            vec[i] -= diffmin;
            vec[i - 1] += diffmin;
            k -= diffmin;
        }

        long long ans = 0;
        for (int i = 0; i <= 1e5; i++) {
            if (vec[i] > 0) {
                ans += vec[i] * i * i;
            }
        }
        return ans;
    }
};