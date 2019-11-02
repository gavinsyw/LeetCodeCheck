// 1092ms, 230.8MB

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0)
            return result;
        int l = words[0].size();
        int wordSize = l * words.size();
        int k = 0;
        while (s.size() >= wordSize+k) {
            bool flag = true;
            vector<string> w = words;
            for (int i = 0; i <= wordSize-l; i+=l) {
                string word = s.substr(k+i, l);
                auto f = find(w.begin(), w.end(), word);
                if (f == w.end()) {
                    flag = false;
                    break;
                }
                *f = "";
            }
            if (flag)
                result.push_back(k);
            k++;
        }
        return result;
    }
};