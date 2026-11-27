class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        if(n < 3) return false;
        long long i = 1;
        while(n > i){
            i *=  3;
            if(i == n)return true;
        }
        return false;

    }
};