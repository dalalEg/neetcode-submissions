class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n= len(nums)
        curr=n-1
        for i in range(n-2,-1,-1):
            if i+nums[i]>=curr:
                curr=i
        return curr==0