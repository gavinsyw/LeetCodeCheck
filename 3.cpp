// 12ms, 9.1MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int maxLen = 0;
        while (i < s.length() && j < s.length()) {
            string::iterator k = find(s.begin()+i, s.begin()+j, s[j]);
            if (k == s.begin()+j) {
                j += 1;
                maxLen = max(maxLen, j-i);
            }
            else {
                i = distance(s.begin(), k)+1;
            }
        }
        return maxLen;
    }
};