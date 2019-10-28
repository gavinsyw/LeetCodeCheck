// 8ms, 8.1MB

class Solution {
public:
    int reverse(int x) {
        long long MAX = pow(2, 31)-1, MIN = -1*pow(2, 31);
        long long sum = 0;
        while (x != 0) {
            sum *= 10;
            int digit = x % 10;
            x /= 10;
            sum += digit;
        }
        if (sum > MAX || sum < MIN) {
            return 0;
        }
        return sum;
    }
};