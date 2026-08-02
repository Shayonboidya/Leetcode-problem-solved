class Solution {
public:
    int t[501][501];
    int solved(int i, int j, vector<int> &nums){
        if(i > j){
            return 0;
        }
        // if(i == j){
        //     return nums[i];
        // }
        if(t[i][j] != -1){
            return t[i][j];
        }
        int take_i = nums[i] + min(solved(i+2, j,nums),solved(i+1, j-1,nums));
        int take_j = nums[j] + min(solved(i, j-2,nums),solved(i+1, j-1,nums));
        return t[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(t,-1,sizeof(t));
        int total_sum = accumulate(piles.begin(),piles.end(),0);
        int alic = solved(0,n-1, piles);
        // int bob = total_sum - alic;

        return alic > total_sum/2;


    }
};