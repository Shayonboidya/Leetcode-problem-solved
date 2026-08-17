class Solution {
public:
    int t[501][501];
    int solved(vector<int>& preSum, int l, int r) {
        if (l >= r) {
            return 0;
        }
        if (t[r][l] != -1) {
            return t[r][l];
        }
        int score = 0;
        for (int mid = l; mid <= r; mid++) {
            int leftSum = preSum[mid] - (l - 1 >= 0 ? preSum[l - 1] : 0);
            int rightSum = preSum[r] - preSum[mid];
            if (leftSum < rightSum) {
                score = max(score, leftSum + solved(preSum, l, mid));
            } else if (leftSum > rightSum) {
                score = max(score, rightSum + solved(preSum, mid + 1, r));
            } else {
                score = max({score, leftSum + solved(preSum, l, mid),
                             rightSum + solved(preSum, mid + 1, r)});
            }
        }
        return t[r][l] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(t, -1, sizeof(t));
        int n = stoneValue.size();

        vector<int> preSum(n, 0);
        preSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + stoneValue[i];
        }

        return solved(preSum, 0, n - 1);
    }
};