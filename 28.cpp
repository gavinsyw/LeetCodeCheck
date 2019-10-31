// 4ms, 9.1MB

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        int k = haystack.size()-needle.size();
        for (int i = 0; i <= k; ++i) {
            bool flag = true;
            for (int j = i; j < i+needle.size(); ++j) {
                if (needle[j-i] != haystack[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};