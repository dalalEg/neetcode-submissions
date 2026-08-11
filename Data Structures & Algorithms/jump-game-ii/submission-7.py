class Solution:
    def jump(self, nums: List[int]) -> int:
        res = 0
        l = r = 0

        while r < len(nums) - 1:
            further = 0
            for i in range(l,r+1):
                further=max(further,i+nums[i])
            res+=1
            l=r+1
            r=further
        return res