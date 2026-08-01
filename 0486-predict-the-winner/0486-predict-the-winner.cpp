class Solution {
public:
    int t[23][23];
    int solved(int i, int j, vector<int> &nums){
        if(i > j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }
        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = nums[i] + min(solved(i+2, j,nums), solved(i+1, j-1,nums));
        int take_j = nums[j] + min(solved(i+1, j-1,nums), solved(i, j-2,nums));

        return t[i][j] =  max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n = nums.size();
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        int player_1 = solved(0, n-1,nums);
        int player_2 = total_score - player_1;

        return player_1 >= player_2;
    }
};