class Solution {
public:
    void marge(vector<int>& v, int l, int m, int r) {
        vector<int> t;
        int i = l, j = m+1;
        while (i <= m && j <= r) {
            if (v[i] <= v[j]) {
                t.push_back(v[i++]);
            } else {
                t.push_back(v[j++]);
            }
        }
        while (i <= m) {
            t.push_back(v[i++]);
        }
        while (j <= r) {
            t.push_back(v[j++]);
        }

        for (int i = 0; i < t.size(); i++) {
            v[l + i] = t[i];
        }
        return;
    }
    void margeSort(vector<int>& v, int l, int r) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        margeSort(v, l, mid);
        margeSort(v, mid+1, r);
        marge(v, l, mid, r);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        margeSort(nums,0,n);
        return nums;
    }
};