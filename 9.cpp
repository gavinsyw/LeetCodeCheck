// 16ms, 8.1MB

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long reversex = 0, cpx = x;
        while (cpx != 0) {
            reversex *= 10;
            reversex += cpx%10;
            cpx /= 10;
        }
        if (reversex == x)
            return true;
        return false;
    }
};