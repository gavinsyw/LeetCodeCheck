// 4ms, 9.3MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        vector<int> a(nums.size());
        copy(nums.begin(), nums.end(), a.begin());
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            int num1 = a[i];
            int num2 = target - a[i];
            vector<int>::iterator num2_pos = find(a.begin()+i+1, a.end(), num2);
            if (num2_pos != a.end()) {
                result[0] = distance(nums.begin(), find(nums.begin(), nums.end(), num1));
                result[1] = distance(nums.begin(), find(nums.begin(), nums.end(), num2));
                if (result[1] == result[0]) {
                    result[1] = distance(nums.begin(), find(nums.begin()+result[0]+1, nums.end(), num2));
                }
                break;
            }
        }
        return result;
    }
};