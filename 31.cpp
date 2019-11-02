// 8ms, 8.5MB

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()-1 <= 0)
            return;
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                int min_value = nums.size()-1;
                while (nums[min_value] <= nums[i]) min_value--;
                swap(nums[i], nums[min_value]);
                for (int j = i+1; j <= (i+nums.size())/2; ++j)
                    swap(nums[j], nums[nums.size()+i-j]);
                return;
            }
        }
        for (int i = nums.size()-1; i >= nums.size()/2; --i) {
            swap(nums[i], nums[nums.size()-1-i]);
        }
        return;
    }
};