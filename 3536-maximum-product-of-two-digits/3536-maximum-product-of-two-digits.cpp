class Solution {
public:
    int maxProduct(int n) {
        int a = -1, b = -1;
        while(n > 0){
            int r = n % 10;
            if(r >= a){
                b = a;
                a = r;
            }
            else if(a > b && b < r){
                b = r;
            }
            n /= 10;
        }
        return a * b;
    }
};