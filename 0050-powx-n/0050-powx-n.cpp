class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long binform = n;
        if(binform < 0){
            x =1/x;
            binform = -binform;
        }
        double ans = 1;
        while(binform > 0){
            if(binform&1){
                ans *= x;
            }
            x *= x;
            binform >>= 1;
        }
        return ans;
        
    }
};