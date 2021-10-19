// 7ms, 6.4MB

class Solution {
public:
    string multiply(string num1, string num2) {
        string num; // number reversed
        if (num1 == "0" || num2 == "0")
            return "0";
        int l1 = num1.size();
        int l2 = num2.size();
        for (int i = l1-1; i >= 0; --i) {
            int x1 = (char)num1[i] - 48;
            int addi = 0;
            for (int j = l2-1; j >=0; --j) {
                int x2 = (char)num2[j] - 48;
                if (num.size() <= l1-1-i+l2-1-j) {
                    int curDigit = (x1 * x2 + addi) % 10;
                    addi = (x1 * x2 + addi) / 10;
                    num += (char)(curDigit + 48);
                }
                else {
                    int numDigit = (char)num[l1-1-i+l2-1-j] - 48;
                    int curDigit = (x1 * x2 + numDigit + addi) % 10;
                    addi = (x1 * x2 + numDigit + addi) / 10;
                    num[l1-1-i+l2-1-j] = (char)(curDigit + 48);
                }
            }
            if (addi != 0) {
                num += (char)(addi+48);
            }
        }
        reverse(num.begin(), num.end());
        return num;
    }
};