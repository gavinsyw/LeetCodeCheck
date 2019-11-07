// 8ms, 8.9MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        if (nums[nums.size()-1] < target)
            return nums.size();
        int s = 0, e = nums.size(), m;
        while (nums[s] < target && s < e-1) {
            m = (s+e)/2-1;
            if (nums[m] < target)
                s = m+1;
            else
                e = m+1;
        }
        return s;
    }
};