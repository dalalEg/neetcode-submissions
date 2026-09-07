class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1,n2=len(s1),len(s2)
        if n1+n2!=len(s3):
            return False
      
        dp=[[False]*(n1+1) for _ in range(n2+1)]
        dp[n2][n1] = True
        for i in range(n2,-1,-1):
            for j in range(n1,-1,-1):
                if i < n2 and s2[i]==s3[i+j] :
                    dp[i][j] =dp[i][j] or dp[i+1][j]
                if j < n1 and s1[j]==s3[i+j] :
                    dp[i][j] =dp[i][j] or dp[i][j+1]
            
        return dp[0][0]