class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int st = 1, end = v.size()-2;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(v[mid] > v[mid-1] && v[mid] > v[mid+1]) return mid;
            else if(v[mid] > v[mid-1]) st = mid +1;
            else end = mid -1;
        }
        return -1;
    }
};