// 8ms, 8.7MB

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        sort(nums.begin(), nums.end());
        int dis = 1000000;
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum-target) < dis) {
                    result = sum;
                    dis = abs(sum-target);
                }
                if (sum - target > 0)
                    k--;
                else if (sum - target < 0)
                    j++;
                else
                    return result;
            }
        }
        return result;
    }
};