class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        def robFrom(start:int,end:int,dp:List[int]):
            dp[end]=nums[end]
            for i in range (end-1,start-1,-1):
                if i!= n-2:
                    dp[i]=max(nums[i]+dp[i+2],dp[i+1])
                else:
                    dp[i]=max(nums[i],dp[i+1])
            return dp[start]
        res1=robFrom(0,n-2,[0]*n)
        res2=robFrom(1,n-1,[0]*n)
        return max(res1,res2)