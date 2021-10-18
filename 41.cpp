// 12ms, 8.7MB

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = nums.size(), i = 0;
        while (i < l) {
            int num = nums[i];
            if (num > 0 && num <= l) {
                cout << nums[i] << " " << nums[num-1] << endl;
                if (nums[i] != nums[num-1])
                    swap(nums[i], nums[num-1]);
                else i++;
            }
            else i++;
        }
        for (int num:nums) cout << num << " ";
        for (auto i = 0; i < l; ++i) {
            if (nums[i] != i+1)
                return i+1;
        }
        return l+1;
    }
};