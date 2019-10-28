// 100ms, 15.8MB

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {

            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> a = {nums[i], nums[j], nums[k]};
                    result.push_back(a);
                    while (j < k && nums[j] == a[1]) j++;
                    while (j < k && nums[k] == a[2]) k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
    
};