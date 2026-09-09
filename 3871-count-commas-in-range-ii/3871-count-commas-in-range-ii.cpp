#define ll long long
class Solution {

public:
    long long countCommas(long long n) {
        ll res = 0;
        ll lower = 1000;
        ll commos = 1;
        while(lower <= n){
            ll upper = lower * 1000 -1;
            if(upper > n) upper = n;
            ll totalNumber = upper - lower + 1;
            res += totalNumber * commos;
            commos++;
            lower = lower * 1000;
        }
        return res;
    }
};