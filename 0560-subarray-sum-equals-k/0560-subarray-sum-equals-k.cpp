class Solution {
public:
    int subarraySum(vector<int>& v, int k) {

        int n = v.size(), cnt = 0;

        // prefix sum array তৈরি করা
        vector<int>prefixSum(n,0);

        // প্রথম element initialize
        prefixSum[0] = v[0];

        // prefix sum build করা
        for(int i =1; i < n;i++){
            prefixSum[i] = prefixSum[i-1] + v[i];
        }

        // map: prefix sum কতবার এসেছে সেটা count রাখবে
        unordered_map<int,int>mp;

        // প্রতিটা index consider করা হচ্ছে
        for(int j = 0; j<n;j++){

            // যদি শুরু থেকেই (0 to j) subarray sum == k হয়
            if(prefixSum[j] == k){
                cnt++;
            }

            // এমন prefix খুঁজছি যেটা বাদ দিলে sum k হবে
            int val = prefixSum[j] - k;

            // যদি এই val আগে থেকে map এ থাকে
            if(mp.find(val) != mp.end()){
                cnt += mp[val]; // যতবার আছে, ততগুলো subarray পাওয়া যাবে
            }

            // current prefixSum map এ initialize করা (না থাকলে)
            if(mp.find(prefixSum[j]) == mp.end()){
                mp[prefixSum[j]] = 0;
            }

            // current prefixSum এর count বাড়ানো
            mp[prefixSum[j]] ++;
        }

        return cnt; // মোট subarray count return
    }
};