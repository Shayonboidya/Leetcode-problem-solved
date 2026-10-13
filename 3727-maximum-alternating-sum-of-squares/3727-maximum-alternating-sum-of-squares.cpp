class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        // sort(nums.begin(), nums.end());
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        long long largeSum = accumulate(nums.begin() + n / 2, nums.end(), 0LL);
        long long smallSum =
            accumulate(nums.begin(), nums.begin() + n / 2, 0LL);
        return largeSum - smallSum;
    }
};