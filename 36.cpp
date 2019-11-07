// 16ms, 9.8MB

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> if_used_base(9, false);
        for (int i = 0; i < 9; ++i) {
            vector<bool> if_used = if_used_base;
            for (int j = 0; j < 9; ++j)  {
                if (board[i][j] == '.')
                    continue;
                else {
                    if (if_used[board[i][j] - '1'])
                        return false;
                    if_used[board[i][j] - '1'] = true;
                }
            }
        }
        for (int j = 0; j < 9; ++j) {
            vector<bool> if_used = if_used_base;
            for (int i = 0; i < 9; ++i)  {
                if (board[i][j] == '.')
                    continue;
                else {
                    if (if_used[board[i][j] - '1'])
                        return false;
                    if_used[board[i][j] - '1'] = true;
                }
            }
        }
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                vector<bool> if_used = if_used_base;
                for (int i = k*3; i < 3+k*3; ++i) {
                    for (int j = l*3; j < 3+l*3; ++j) {
                        if (board[i][j] == '.')
                            continue;
                        else {
                            if (if_used[board[i][j] - '1'])
                                return false;
                            if_used[board[i][j] - '1'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};