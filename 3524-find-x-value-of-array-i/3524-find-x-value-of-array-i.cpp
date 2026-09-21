class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k, 0);
        vector<long long> prevCount(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> currCount(k, 0);
            int currentElemntRem = nums[i] % k;
            currCount[currentElemntRem]++;
            for (int oldRem = 0; oldRem <= k - 1; oldRem++) {
                int newRem = ((long long)oldRem * nums[i] % k) % k;
                currCount[newRem] += prevCount[oldRem];
            }
            prevCount = move(currCount);
            for (int i = 0; i <= k - 1; i++) {
                res[i] += prevCount[i];
            }
        }
        return res;
    }
};