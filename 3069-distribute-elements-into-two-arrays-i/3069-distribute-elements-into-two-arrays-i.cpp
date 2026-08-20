class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return nums;
        }
        vector<int> a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        int i = 2;
        while(i < n){
            if(a1.back() > a2.back()){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
            i++;
        }
        vector<int>res;
        for(int x:a1){
            res.push_back(x);
        }
        for(int x:a2){
            res.push_back(x);
        }
        return res;
    }
};