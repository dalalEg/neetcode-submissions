class Solution:
    def jump(self, nums: List[int]) -> int:
 
        n=len(nums)
        dp=[n]*(n+1)
        dp[0]=0
        for i in range(n):
            for j in range(i,i+nums[i]+1):
                if j < n:
                    dp[j]=min(dp[j],dp[i]+1)
        return dp[n-1]