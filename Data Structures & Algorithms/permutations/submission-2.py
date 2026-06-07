class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        res=[]
        used=[False] * len(nums)
        def generate(curr):
            if len(curr)==len(nums):
                res.append(curr.copy())
                return 
            for i in range(len(nums)):
                if used[i]:
                    continue
                used[i]=True
                curr.append(nums[i])
                generate(curr)
                curr.pop()
                used[i]=False
        generate([])
        return res