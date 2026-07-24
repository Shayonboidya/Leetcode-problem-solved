class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGCD.push_back(__gcd(mx, nums[i]));
        }

        sort(prefixGCD.begin(), prefixGCD.end());
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += __gcd(prefixGCD[i], prefixGCD[n - i - 1]);
        }
        return ans;
    }
};