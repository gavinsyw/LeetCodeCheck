// 20ms, 9.9MB

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            int water = min(height[i], height[j])*(j-i);
            if (water > maxWater)
                maxWater = water;
            if (height[j] < height[i])
                j--;
            else
                i++;
        }
        return maxWater;
    }
};