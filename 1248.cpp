// 180ms, 20.5MB

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odd_pos;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] % 2 == 1)
                odd_pos.push_back(i);
        if (odd_pos.size() < k)
            return 0;
        int num_subarray = 0;
        
        for (int i = 0; i <= odd_pos.size()-k; ++i) {
            int front_space, end_space;
            if (i == 0)
                front_space = odd_pos[i];
            else
                front_space = odd_pos[i] - odd_pos[i-1] - 1;
            if (i == odd_pos.size()-k)
                end_space = nums.size()-1-odd_pos[i+k-1];
            else
                end_space = odd_pos[i+k] - odd_pos[i+k-1]-1;
            num_subarray += (front_space+1) * (end_space+1);
        }
        
        return num_subarray;
    }
};