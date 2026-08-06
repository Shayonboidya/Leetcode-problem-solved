class Solution {
public:
    long long getMul(int n){
        long long product = 1;
        while(n > 0){
            product *= (n % 10);
            n /= 10;
        } 
        return product;
    }
    int smallestNumber(int n, int t) {
        while(n <= 100){
            long long res = getMul(n);
            if(res % t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};