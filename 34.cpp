// 4ms, 16.4MB

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        return range(nums, target, 0, nums.size());
    }
    
    vector<int> range(vector<int>& nums, int target, int s, int e) {
        vector<int> result(2, -1);
        if (s+1 >= e && nums[s] != target)
            return result;
        if (nums[s] == target && nums[e-1] == target) {
            result = {s, e-1};
            return result;
        }
        int m = (s+e)/2;
        if (nums[m-1] == target) {
            result[0] = range(nums, target, s, m)[0];
            result[1] = (range(nums, target, m, e)[1] != -1)?range(nums, target, m, e)[1]:m-1;
            return result;
        }
        else if (nums[m-1] < target)
            return range(nums, target, m, e);
        else
            return range(nums, target, s, m);
    }

};