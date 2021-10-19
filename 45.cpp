// 802ms, 17MB (bad solution)

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> min_step(nums.size(), 100000);
        min_step[nums.size()-1] = 0;
        for (int i = nums.size()-2; i >=0; --i) {
            int edp = (i+nums[i]>nums.size()-1) ? nums.size()-1:i+nums[i];
            for (int j = i+1; j <= edp; ++j) {
                min_step[i] = (min_step[i]<min_step[j]+1)?min_step[i]:min_step[j]+1;
            }
        }
        return min_step[0];
    }
};