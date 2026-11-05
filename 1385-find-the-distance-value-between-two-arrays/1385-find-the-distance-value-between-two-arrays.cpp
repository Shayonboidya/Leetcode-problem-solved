class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            bool isGratter = true;
            for (int j = 0; j < m; j++) {
                int t = abs(arr1[i] - arr2[j]);
                if (t <= d) {
                    isGratter = false;
                }
            }
            if(isGratter) cnt++;
        }
        return cnt;
    }
};