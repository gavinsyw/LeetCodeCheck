// 125ms, 11.1MB

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0) {
            for (int j = 0; j < p.size(); ++j) 
                if (p[j] != '*')
                    return false;
            return true;
        }
        vector<vector<bool>> valid_match(s.size(), vector<bool>(p.size(), 0));
        int j = 0;
        bool preMatch = (s[0] == p[0]) || (p[0] == '?');
        if (symbMatch(s[0], p[0])) {
            valid_match[0][0] = true;
        }
        else {
            return false;
        }
        for (int j = 1; j < p.size(); ++j) {
            if (preMatch) {
                valid_match[0][j] = (p[j] == '*' && valid_match[0][j-1]);
            }
            else {
                valid_match[0][j] = (valid_match[0][j-1] && symbMatch(s[0], p[j]));
                preMatch = (s[0] == p[j]) || (p[j] == '?');
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            valid_match[i][0] = (valid_match[i-1][0] && p[j] == '*');
            for (int j = 1; j < p.size(); ++j) {
                valid_match[i][j] = (valid_match[i-1][j] && p[j] == '*') || (valid_match[i-1][j-1] && symbMatch(s[i], p[j])) || (valid_match[i][j-1] && p[j] == '*');
            }
        }
        return valid_match[s.size()-1][p.size()-1];
    }
    
    bool symbMatch(char a, char b) {
        return (a == b) || (b == '?') || (b == '*');
    }
};