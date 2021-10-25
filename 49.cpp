// 1872ms, 24.5MB (bad solution)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        vector<int> digitNum;
        vector<string> digitCnt;
        for (int i = 0; i < strs.size(); ++i) {
            int n = strs[i].size();
            bool flag1 = false;
            for (int j = 0; j < digitNum.size(); ++j) {
                if (n == digitNum[j])
                    flag1 = true;
            }
            vector<int> cnt(26, 0);
            for (int j = 0; j < n; ++j) {
                cnt[strs[i][j]-97] += 1;
            }
            string cnt2;
            for (int j = 0; j < 26; ++j) {
                cnt2 += (char)cnt[j];
            }
            if (flag1 == false) {
                digitCnt.push_back(cnt2);
                digitNum.push_back(n);
                vector<string> tmp(1, strs[i]);
                group.push_back(tmp);
            }
            else {
                int idx = -1;
                for (int j = 0; j < digitCnt.size(); ++j) {
                    if (cnt2 == digitCnt[j]) {
                        idx = j;
                        break;
                    }
                }
                if (idx == -1) {
                    digitCnt.push_back(cnt2);
                    digitNum.push_back(n);
                    vector<string> tmp(1, strs[i]);
                    group.push_back(tmp);
                }
                else {
                    group[idx].push_back(strs[i]);
                }
            }
        }
        return group;
    }
};