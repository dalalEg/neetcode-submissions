class Solution:
    def longestPalindrome(self, s: str) -> str:
        n= len(s)
        maxLen,leftIndex=0,0
        for i in range(n):
            l,r=i,i
            while l>=0 and r <n and s[l]==s[r]:
                if r-l+1 > maxLen:
                    maxLen=r-l+1
                    leftIndex=l
                l-=1
                r+=1
            l,r=i,i+1
            while l>=0 and r <n and s[l]==s[r]:
                if r-l+1 > maxLen:
                    maxLen=r-l+1
                    leftIndex=l
                l-=1
                r+=1
        
        return s[leftIndex:maxLen+leftIndex]