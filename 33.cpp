// 0ms, 8.8MB

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bSearch(nums, target, 0, nums.size());
    }
    
    int bSearch(vector<int>& nums, int target, int start, int end) {
        cout << start << " " << end << endl;
        if (start >= end)
            return -1;
        if (nums[start] == target)
            return start;
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        int a = nums[start], b = nums[mid], c = nums[end];
        if (b < a) {
            if (target > a || target < b) 
                return bSearch(nums, target, start, mid);
            else
                return bSearch(nums, target, mid+1, end);
        }
        else {
            if (target < b && target > a)
                return bSearch(nums, target, start, mid);
            else
                return bSearch(nums, target, mid+1, end);
        }
    }
};