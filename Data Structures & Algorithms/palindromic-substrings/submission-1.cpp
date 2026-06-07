class Solution {
public:
    int countSubstrings(string s) {
        int n =s.size() , res=n;
        for (int i=0;i<n;i++){
            int l=i-1,r=i+1;
            while (i>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
                res+=1;
            }
            l=i,r=i+1;
            while (i>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
                res+=1;
            }
        }
        return res;
    }  
};
