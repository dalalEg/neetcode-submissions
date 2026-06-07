class Solution {
public:
    bool isHappy(int n) {
       set<int> st;
       st.insert(n);
       while(n){
         int curr= 0;
        while (n){
            curr+=(n%10)*(n%10);
            n/=10;
        }
        if (curr==1) return true;
         if (st.find(curr)!=st.end())
            return false;
        st.insert(curr);
         n=curr;
       }
       return true; 
    }
};
