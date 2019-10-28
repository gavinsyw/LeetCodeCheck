// 16ms, 12.5MB

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows, "");
        int cnt = 0, m = s.length();
        while (cnt < m) {
            for (int i = 0; i < numRows && cnt < m; ++i) {
                rows[i] += s[cnt];
                cnt++;
            }
            for (int i = numRows-2; i > 0 && cnt < m; --i) {
                rows[i] += s[cnt];
                cnt++;
            }
        }
        string result = "";
        for (int i = 0; i < numRows; ++i) {
            result += rows[i];
        }
        return result;
    }
};