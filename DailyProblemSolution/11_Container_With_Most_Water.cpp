// problem link: https://leetcode.com/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            
            int width = right - left;
            
            
            int h = std::min(height[left], height[right]);
            
           
            int current_area = width * h;
            
            
            max_area = std::max(max_area, current_area);
            
           
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};