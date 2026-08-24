class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res=[1]*n
        for i in range(1,n):
            res[i]=res[i-1]*nums[i-1]
        post=1
        for i in range(n-1,-1,-1):
            res[i]=post*res[i]
            post=post*nums[i]
        return res
        