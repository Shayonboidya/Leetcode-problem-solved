class Solution {
public:
    double myPow(double x, int n) {
        long bits = n;
        if (x == 0)
            return 0;
        if (x == 1 || n == 0)
            return 1;
        bool sign = true;
        if (n < 0) {
            sign = false;
            bits = -bits;
        }
        double sum = 1;
        while (bits > 0) {
            if (bits & 1) {
                sum *= x;
            }
            x *= x;
            bits >>= 1;
        }
        return sign ? sum : 1 / sum;
    }
};