class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        int st = 0, end = v.size()-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(mid == 0 && (v[0] != v[1])) return v[mid];
            if(mid == n-1 && (v[n-1] != v[n-2])) return v[mid];

            if((v[mid -1] != v[mid]) && (v[mid] != v[mid +1])) return v[mid];
            if(mid %2 == 0){//even
                if(v[mid] == v[mid -1]) end = mid -1;//left
                else st = mid +1;//right
            }else{
                if(v[mid] == v[mid-1]) st = mid +1;//right
                else end = mid -1;//left
            }
        }
        return -1;
    }
};