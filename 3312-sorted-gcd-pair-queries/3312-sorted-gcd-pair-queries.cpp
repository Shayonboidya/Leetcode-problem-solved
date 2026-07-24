class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> divisorFreq(mx+1, 0);
        for(int i = 0;i < n;i++){
            int num = nums[i];
            for(int j = 1;j*j <= num; j++){
                if(num % j == 0){
                    divisorFreq[j]++;
                    if(num/j != j){
                        divisorFreq[num/j]++;
                    }
                }
            }
        }

        vector<long long> pirwasegcd(mx+1,0);

        for(int g = mx; g >= 1;g--){
            int cnt = divisorFreq[g];
            pirwasegcd[g] = 1LL * cnt * (cnt - 1)/2;

            for(int mul = g*2; mul <= mx; mul += g){
                pirwasegcd[g] -= pirwasegcd[mul];
            }
        }
        
        vector<long long> prefixcountgdc(mx+1,0);
        for(int i = 1 ;i <= mx;i++){
            prefixcountgdc[i] = prefixcountgdc[i-1] + pirwasegcd[i];
        }
        vector<int> res;
        for(long long x:queries){
            int l = 1, r = mx, t = mx;
            while(l <= r){
                int mid = l + (r - l)/2;

                if(prefixcountgdc[mid] >= x+1){
                    t = mid;
                    r = mid-1;
                }else{
                    l = mid + 1;
                }
            }
            res.push_back(t);
        }
        return res;
    }
};