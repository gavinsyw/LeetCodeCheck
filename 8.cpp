// 4ms, 8.6MB

class Solution {
public:
    int myAtoi(string str) {
        long long sum = 0;
        long long MAX = 2147483647, MIN = -2147483648;
        int m = str.length(), sign = 1;
        bool valid_flag = true;
        for (int i = 0; i < m; ++i) {
            if (str[i] == ' ' && valid_flag)
                continue;
            else if (str[i] == '-' && valid_flag) {
                sign = -1;
                valid_flag = false;
            }
            else if (str[i] == '+' && valid_flag) {
                sign = 1;
                valid_flag = false;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                sum *= 10;
                sum += str[i]-'0';
                valid_flag = false;
                if (sum > MAX+1 || sum < MIN)
                    break;
            }
            else
                break;
        }
        sum *= sign;
        if (sum < MIN)
            return MIN;
        if (sum > MAX)
            return MAX;
        return sum;
    }
};