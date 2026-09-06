#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        int l = 0;
        int r = height.size() - 1;
        
        int left_max = height[l];
        int right_max = height[r];
        
        int trapped_water = 0;
        
        while (l < r) {
            if (left_max < right_max) {
                l++;
                left_max = std::max(left_max, height[l]);
                trapped_water += left_max - height[l];
            } else {
                r--;
                right_max = std::max(right_max, height[r]);
                trapped_water += right_max - height[r];
            }
        }
        
        return trapped_water;
    }
};