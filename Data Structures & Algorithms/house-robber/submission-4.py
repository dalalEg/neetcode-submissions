class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        dp=nums
        for i in range(1,n):
            if i==1:
                dp[i]=max(dp[i-1],nums[i])
                continue
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])

        return dp[n-1]