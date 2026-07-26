class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int mx3 = INT_MIN;
        int mi1 = INT_MAX;
        int mi2 = INT_MAX;
        for (int a : nums) {
            if (mx1 < a) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = a;
            } else if (a > mx2) {
                mx3 = mx2;
                mx2 = a;
            } else if (a > mx3){
                mx3 = a;
            }
        }
        for (int a : nums) {
            if (a < mi1) {
                mi2 = mi1;
                mi1 = a;
            } else if (a < mi2) {
                mi2 = a;
            }
        }

        return max((mx1 * mx2 * mx3), (mx1 * mi1 * mi2));
    }
};