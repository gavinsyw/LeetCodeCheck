// 52ms, 16MB

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0)
            return {};
        map <int, vector<vector<int>>> solutionSet;
        for (int c:candidates) {
            for (int i = 0; i < target+1; ++i) {
                if (i == c) {
                    if (solutionSet.find(i) == solutionSet.end())
                        solutionSet[i] = {{i}};
                    else
                        solutionSet[i].push_back({i});
                }
                else if (i-c>0 && solutionSet.find(i-c) != solutionSet.end()) {
                    for (vector<int> x:solutionSet[i-c]) {
                        vector<int> y = x;
                        y.push_back(c);
                        if (solutionSet.find(i) == solutionSet.end())
                            solutionSet[i] = {y};
                        else
                            solutionSet[i].push_back(y);
                    }
                }
            }
        }
        
        if (solutionSet.find(target) == solutionSet.end())
            return {};
        else
            return solutionSet[target];
    }
};