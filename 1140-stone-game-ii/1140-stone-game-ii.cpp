class Solution {
public:
    int n;
    int t[2][101][101];
    int solvedForAlic(int person, int idx, int m, vector<int>& v) {
        if (idx >= n) {
            return 0;
        }
        if (t[person][idx][m] != -1) {
            return t[person][idx][m];
        }
        int res = (person == 1) ? -1 : INT_MAX;

        int stone = 0;
        for (int x = 1; x <= min(2 * m, n - idx); x++) {

            stone += v[idx + x - 1];
            if (person) {
                res = max(res,
                          (stone + (solvedForAlic(0, idx + x, max(m, x), v))));
            } else {
                res = min(res, solvedForAlic(1, idx + x, max(m, x), v));
            }
        }
        return t[person][idx][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        n = piles.size();
        return solvedForAlic(1, 0, 1, piles);
    }
};