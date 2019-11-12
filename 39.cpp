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

// another solution, 28ms, 15.4MB

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0)
            return {};
        vector<vector<int>> result = {};
        vector<vector<vector<int>>> solutionSet(target+1, result);
        for (int c:candidates) {
            for (int i = 0; i < target+1; ++i) {
                if (i == c) {
                    solutionSet[i].push_back({i});
                }
                else if (i-c>0 && solutionSet[i-c].size() != 0) {
                    for (vector<int> x:solutionSet[i-c]) {
                        vector<int> y = x;
                        y.push_back(c);
                        solutionSet[i].push_back(y);
                    }
                }
            }
        }
        return solutionSet[target];
    }
};