class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chs;
        int n = s.length();
        int l=0,r=0;
        int res=0;
        while(r<n){
           while(chs.count(s[r])>0){
             chs.erase(s[l]);
            l++;

           }
           res=max(res,r-l+1);
           chs.insert(s[r]);
           r++;
        }
        return res;
    }
};
