class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n= len(s)+1
        dp=[False]*n
        dp[n-1]=True
        for i in range (n-2,-1,-1):
            for word in wordDict:
                if i+len(word) < n and word==s[i:i+len(word)]:
                    dp[i]=dp[i+len(word)]
                
                if dp[i]:
                    break
        return dp[0]
        