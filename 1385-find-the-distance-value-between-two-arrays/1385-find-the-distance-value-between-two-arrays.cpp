class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr2.size();
        sort(arr2.begin(), arr2.end());
        int cnt = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int j =
                lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            if (j == 0) {
                cnt += arr2[j] - arr1[i] > d;
            } else if (j >= n) {
                cnt += arr1[i] - arr2[n - 1] > d;
            } else {
                cnt += (arr2[j] - arr1[i] > d && arr1[i] - arr2[j - 1] > d);
            }
        }
        return cnt;
    }
};