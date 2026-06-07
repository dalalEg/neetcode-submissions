

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int res = 0;

        while (left < right) {
            res = std::max(res, std::min(heights[left], heights[right]) * (right - left));

            if (heights[left] < heights[right]) {
                left++;  // Move the smaller height
            } else {
                right--; // Move the larger or equal height
            }
        }
        return res;
    }
};