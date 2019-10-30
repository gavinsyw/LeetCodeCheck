// 52ms, 11MB

const vector<string> emptyVec = {};

class Solution {
public:
    vector<string> generateSolution(int n, vector<vector<string>>& resultTable) {
        if (n == 0)
            return {""};
        else if (n == 1)
            return {"()"};
        else {
            vector<string> result;
            for (int i = 0; i < n; ++i) {
                if (resultTable[i] == emptyVec)
                    resultTable[i] = generateParenthesis(i);
                if (resultTable[n-i-1] == emptyVec)
                    resultTable[n-i-1] = generateParenthesis(n-i-1);
                vector<string> leftResult = resultTable[i];
                vector<string> rightResult = resultTable[n-i-1];
                for (string s1: leftResult) {
                    for (string s2: rightResult) {
                        if (find(result.begin(), result.end(), "("+s1+")"+s2) == result.end())
                            result.push_back("("+s1+")"+s2);
                        if (find(result.begin(), result.end(), s1+"("+s2+")") == result.end())
                            result.push_back(s1+"("+s2+")");
                    }
                }
            }    
            return result;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> resultTable;
        for (int i = 0; i < n; ++i)
            resultTable.push_back({});
        return generateSolution(n, resultTable);
    }

};
