class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        post,pre=[1]*n,[1]*n
        for i in range(1,n):
            pre[i]=pre[i-1]*nums[i-1]
        for i in range(n-2,-1,-1):
            post[i]=post[i+1]*nums[i+1]
        res=[1]*n
        for i in range(n):
            res[i]=post[i]*pre[i]
        return res
        