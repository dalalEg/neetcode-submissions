class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if len(text1) < len(text2):
            text1, text2 = text2, text1

        dp = ([0] * (len(text2) + 1))
        j=0
        ch=""
        for i in range(len(text1)-1,-1,-1):
            pre=0
            for j in range(len(text2)-1,-1,-1):
                temp=dp[j]
                if text1[i]==text2[j]:
                    dp[j]=pre+1
                else:
                    dp[j]=max(dp[j+1],dp[j])
                pre=temp
        return dp[0]