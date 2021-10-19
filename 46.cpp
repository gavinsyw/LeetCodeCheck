// 18ms, 9.6 MB (bad solution)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perm;
        if (nums.size() == 1) {
            perm.push_back(nums);
            return perm;
        }
        else {
            for (int i = 0; i < nums.size(); ++i) {
                int reserved = nums[0];
                nums.erase(nums.begin());
                vector<vector<int>> perm2 = permute(nums);
                nums.push_back(reserved);
                for (int j = 0; j < perm2.size(); ++j) {
                    perm2[j].push_back(reserved);
                    perm.push_back(perm2[j]);
                }
            }
            return perm;
        }
    }
};