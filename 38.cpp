// 4ms, 9.1MB

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string sNew="";
            s = s + "0";
            int cnt = 1;
            for (int j = 1; j < s.size(); ++j) {
                if (s[j] != s[j-1]) {
                    sNew += to_string(cnt);
                    sNew += s[j-1];
                    cnt = 1;
                }
                else
                    cnt++;
            }
            s = sNew;
        }
        return s;
    }
};