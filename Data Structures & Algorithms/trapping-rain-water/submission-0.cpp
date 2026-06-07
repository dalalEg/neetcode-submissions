class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()&&height[i]==0)
             continue;
            while(!st.empty()&&height[st.top()]<=height[i]){
                 int mid = st.top(); // valley bottom
                st.pop();

                if (st.empty()) break; // no left wall

                int left = st.top(); // left boundary
                int width = i - left - 1;
                int boundedHeight = min(height[i], height[left]) - height[mid];
                ans += width * boundedHeight;
            }
            st.push(i);
            
        }
        return ans;
    }
};
