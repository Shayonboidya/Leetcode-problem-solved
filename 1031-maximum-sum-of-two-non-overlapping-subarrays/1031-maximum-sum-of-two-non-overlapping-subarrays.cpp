class Solution {
public:
    // Helper function to calculate the maximum sum of two non-overlapping subarrays.
    // Here:
    // l = length of the first subarray
    // m = length of the second subarray
    int maxSumTwoNoOverlapHelper(vector<int>& prefixSum, int l, int m) {
        int n = prefixSum.size();

        // m_end = ending index of the second (m-length) subarray
        // max_l_block_sum = maximum sum of any valid l-length subarray found so far
        // result = maximum total sum of two non-overlapping subarrays
        int m_end = l + m - 1, max_l_block_sum = 0, result = 0;

        // Move the m-length subarray from left to right
        while (m_end < n) {

            // Ending index of the l-length subarray
            int l_end = m_end - m;

            // Index just before the starting index of the l-length subarray
            int l_st = l_end - l;

            // Calculate sum of current m-length subarray
            int m_block_sum = prefixSum[m_end] - prefixSum[l_end];

            // Calculate sum of current l-length subarray
            int l_block_sum =
                prefixSum[l_end] - (l_st < 0 ? 0 : prefixSum[l_st]);

            // Keep track of the maximum l-length subarray sum seen so far
            max_l_block_sum = max(max_l_block_sum, l_block_sum);

            // Update the answer with the best l-block before the current m-block
            result = max(result, max_l_block_sum + m_block_sum);

            // Move the m-length subarray one step to the right
            m_end++;
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        // Build prefix sum array
        // prefixSum[i] = sum of nums[0...i]
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Check both possible orders:
        // 1. firstLen subarray comes before secondLen subarray
        // 2. secondLen subarray comes before firstLen subarray
        return max(
            maxSumTwoNoOverlapHelper(prefixSum, firstLen, secondLen),
            maxSumTwoNoOverlapHelper(prefixSum, secondLen, firstLen)
        );
    }
};