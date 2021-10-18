// 21ms, 15.8MB

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_water = 0;
        int current_height = 0;
        int center = std::distance(height.begin(), max_element(height.begin(), height.end()));
        for (int i = 0; i <= center; ++i) {
            if (height[i] >= current_height) {
                current_height = height[i];
            }
            else {
                total_water += current_height-height[i];
            }
        }
        current_height = 0;
        for (int i = n-1; i >= center; --i) {
            if (height[i] >= current_height) {
                current_height = height[i];
            }
            else {
                total_water += current_height-height[i];
            }
        }
        return total_water;
    }
};