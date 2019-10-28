// 44ms, 9.1MB

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > result;
        if (nums.size() < 4) return result;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i ++)
        {
            for (int j = i + 1; j < nums.size() - 2; j ++)
            {
                int l = j + 1, r = nums.size() - 1;
                while(l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                        l ++;
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                        r --;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l ++;
                        r --;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};