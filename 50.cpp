// 8ms, 5.9MB

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return pow3(x, n);
        return pow2(x, n);
    }
    
    double pow2(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n % 2 == 0) {
            double y = pow2(x, n/2);
            return y * y;
        }
        return pow2(x, n/2) * pow2(x, n/2+1);
    }
    
    double pow3(double x, int n) {
        if (n == 0)
            return 1;
        if (n == -1)
            return 1/x;
        if (n % 2 == 0) {
            double y = pow3(x, n/2);
            return y * y;
        }
        return pow3(x, n/2) * pow3(x, n/2-1);
    }
};