class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); 
        int size = heights.size();
        stack<int> ist;
        int maxArea = 0;
        for (int i = 0; i < size; i++) {
            int curr = 0;
            while (!ist.empty() && heights[ist.top()] > heights[i]) {
                 int height = heights[ist.top()];
                ist.pop();
                int width = ist.empty() ? i : i - ist.top() - 1;
                maxArea = max(maxArea, height * width);

            }
            ist.push(i);
        }
        return maxArea;
    }
};
