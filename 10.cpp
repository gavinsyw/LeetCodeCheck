// 4ms, 8.2MB

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool sol[m+1][n+1];
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j)
                sol[i][j] = false;
        sol[0][0] = true;
        for (int p1 = 0; p1 <= m; ++p1)
            for (int p2 = 1; p2 <= n; ++p2) {
                if (p[p2-1] == '*') {
                    sol[p1][p2] = (p2 > 1) && (sol[p1][p2-2] || (p1 > 0 && (s[p1-1] == p[p2-2] || p[p2-2] == '.') && sol[p1-1][p2]));
                }
                else if (p1 == 0)
                    sol[p1][p2] = false;
                else
                    sol[p1][p2] = sol[p1-1][p2-1] && (p[p2-1] == '.' || (s[p1-1] == p[p2-1]));
            }
        return sol[m][n];
    }
};