// 0ms, 8.1MB

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
            sign = -1;
        long a = labs(dividend);
        long b = labs(divisor);
        long tmp = b, cnt = 1, c = 0;
        while (tmp << 1 <= a) {
            tmp = tmp << 1;
            cnt = cnt << 1;
        }
        while (b <= a) {
            if (tmp <= a) {
                a -= tmp;
                c += cnt;
            }
            tmp = tmp >> 1;
            cnt = cnt >> 1;
        }
        c = c * sign;
        if (sign == 1)
            if (c < INT_MAX)
                return c;
            else
                return INT_MAX;
        if (sign == -1)
            if (c > INT_MIN)
                return c;
            else 
                return INT_MIN;
        return INT_MAX;
    }
};