class Solution {
public:
    string longestPalindrome(string s) {
        int res=0,size=s.length();
        int start=0;
        for (int i =0;i<size;i++){
            int l=i,r=i;
            while (l>=0 && r<size && s[l]==s[r]){
                 if (r-l+1>res){
                res=r-l+1;
                start=l;
            }
                l--;
                r++;
            }
           
            l=i,r=i+1;
            while (l>=0 && r<size && s[l]==s[r]){
                 if (r-l+1>res){
                res=r-l+1;
                start=l;
            }
                l--;
                r++;
            }
        
        }
        return s.substr(start,res);
    }
};
