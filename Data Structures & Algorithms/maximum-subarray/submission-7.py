class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s=0
        res=float('-inf')
        for num in nums:
            s=num+s
            res=max(res,s)
            s=max(0,s)
        return res