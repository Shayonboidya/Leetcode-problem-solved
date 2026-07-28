class Solution {
public:
    int maxSumTwoNoOverlapHelper(vector<int>& prefixSum, int l, int m) {
        int n = prefixSum.size();

        int m_end = l + m - 1, max_l_block_sum = 0, result = 0;
        while (m_end < n) {
            int l_end = m_end - m, l_st = l_end - l;
            int m_block_sum = prefixSum[m_end] - prefixSum[l_end];
            int l_block_sum =
                prefixSum[l_end] - (l_st < 0 ? 0 : prefixSum[l_st]);
            max_l_block_sum = max(max_l_block_sum, l_block_sum);
            result = max(result, max_l_block_sum + m_block_sum);
            m_end++;
        }
        return result;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        return max(maxSumTwoNoOverlapHelper(prefixSum, firstLen, secondLen),
                   maxSumTwoNoOverlapHelper(prefixSum, secondLen, firstLen));
    }
};