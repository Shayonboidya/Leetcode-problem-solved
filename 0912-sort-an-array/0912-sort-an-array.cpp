class Solution {
public:
    // quick sort


    int partition(vector<int>&v, int l, int r){
        int randomIdx = l + rand() % (r - l +1);
        swap(v[randomIdx], v[r]);
        int pivote = v[r];
        int pi = l;
        for(int i = l; i < r;i++){
            if(pivote > v[i]){
                swap(v[pi], v[i]);
                pi++;
            }
        }
        swap(v[pi],v[r]);
        return pi;
    }
    void QuiackSort(vector<int>& v, int l, int r) {
        if (l >= r)
            return;
        int pivote = partition(v,l, r);
        QuiackSort(v, l, pivote-1);
        QuiackSort(v, pivote+1, r);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        QuiackSort(nums,0,n);
        return nums;
    }
};