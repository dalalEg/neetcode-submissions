class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        dp = nums[1:]
        dp2 = nums[:len(nums)-1]
        pre1=pre2=0
        for i in range(len(dp)):
            dp[i]=max(dp[i]+pre1,pre2)
            pre1=pre2
            pre2=dp[i]
        pre1=pre2=0
        for i in range(len(dp2)):
            dp2[i]=max(dp2[i]+pre1,pre2)
            pre1=pre2
            pre2=dp2[i]
              
        return max(max(dp),max(dp2))
