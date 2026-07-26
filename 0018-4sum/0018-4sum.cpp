class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        int n = v.size();
        sort(v.begin(),v.end());

        for(int i = 0; i< n;i++){
            if(i > 0 && v[i] == v[i-1]) continue;

            for(int j = i+1; j < n;){
                int p = j+1,q = n-1;

                while(p < q){
                    long long sum = (long long)v[i] + (long long)v[j]
                    + (long long)v[p] + (long long)v[q];

                    if(sum < target){
                        p++;
                    }else if(sum > target){
                        q--;
                    }else{
                        ans.push_back({v[i],v[j],v[p],v[q]});
                        p++;q--;

                        while(p < q && v[p] == v[p-1])p++;
                    }
                }
            j++;
            while(j < n && v[j] == v[j-1])j++;
            }
        }
        return ans;
    }
};