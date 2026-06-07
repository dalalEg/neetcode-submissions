class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size(),ans=0;
        for (int i=0;i<=n;i++){
            int h=heights[i];
            while(!st.empty()&&(h<=heights[st.top()]||i==n)){
                int height = heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                ans=max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};
