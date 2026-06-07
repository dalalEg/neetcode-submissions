class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count=[0]*92
        l,r=0,0
        res=0
        while r < len(s):
            count[ord(s[r]) - ord(' ')] += 1
            while  count[ord(s[r]) - ord(' ')] !=1:
                count[ord(s[l]) - ord(' ')]-=1
                l+=1
            res = max(res,r-l+1)
            r+=1
        return res