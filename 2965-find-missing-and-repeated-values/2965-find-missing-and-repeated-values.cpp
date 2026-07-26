class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        vector<int>a;
        unordered_set<int>s;
        int n= v.size();
        int acctualSum = n*n * (n*n +1)/2, currentSum = 0;
        for(int i = 0; i< n;i++){
            for(int j = 0;j < n;j++){
                currentSum += v[i][j];
                if(s.find(v[i][j])!= s.end()){
                    a.push_back(v[i][j]);
                }
                s.insert(v[i][j]);
            }
        }

        a.push_back(acctualSum - currentSum + a[0]);

        return {a[0],a[1]};
        
    }
};