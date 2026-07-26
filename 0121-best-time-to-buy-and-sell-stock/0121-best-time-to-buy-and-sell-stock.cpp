class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = prices[0], mp = 0;
        for(int i = 1;i < prices.size();i++){
            if(b < prices[i]){
                mp = max(mp, prices[i] - b);
            }
            b = min(b,prices[i]);
        }
        return mp;
    }
};