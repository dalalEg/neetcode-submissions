class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (int num:nums){
            st.insert(num);
        }
        int res=0;
        for(int s:st){
            if(st.find(s-1)==st.end()){
                int l=1;
                while(st.find(s+l)!=st.end()){
                    l++;
                }
                res=max(res,l);
            }
        }
        return res;
    }
};
