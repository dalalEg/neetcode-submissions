class Solution:
    def countSubstrings(self, s: str) -> int:
        n= len(s)
        res=0
        for i in range(n):
            l,r=i,i
            while l>=0 and r <n and s[l]==s[r]:
                res+=1
                maxLen=r-l+1
                leftIndex=l
                l-=1
                r+=1
            l,r=i,i+1
            while l>=0 and r <n and s[l]==s[r]:
                maxLen=r-l+1
                res+=1
                leftIndex=l
                l-=1
                r+=1
        
        return res