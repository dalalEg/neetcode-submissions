class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0,l=0,n=s.length();
        vector<int> count(92,0);
        int res=0;
        while (r<n){
            count[s[r]-' ']++;
            while(count[s[r]-' ']>1){
                count[s[l]-' ']--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;

    }
};
