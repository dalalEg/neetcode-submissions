class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        res=float('-inf')
        n=len(nums)
        for i in range(n):
            currSum=0
            for j in range(i,i+n):
                currSum+=nums[j%n]
                res=max(res,currSum)
        return res