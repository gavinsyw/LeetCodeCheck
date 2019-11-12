// 12ms, 14.3MB

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return cbSum(candidates, target, 0, candidates.size());
    }
    
    vector<vector<int>> cbSum(vector<int>& candidates, int target, int s, int e) {
        if (s >= e)
            return {};
        if (candidates[s] > target)
            return {};
        if (candidates[s] == target)
            return {{candidates[s]}};
        if (e-s == 1) 
            return {};
        vector<vector<int>> subresult = cbSum(candidates, target-candidates[s], s+1, e);
        int t = s+1;
        while (t < e && candidates[t] == candidates[t-1]) t++;
        vector<vector<int>> result = cbSum(candidates, target, t, e);
        for (vector<int> r:subresult) {
            r.push_back(candidates[s]);
            result.push_back(r);
        }
        return result;
    }
};