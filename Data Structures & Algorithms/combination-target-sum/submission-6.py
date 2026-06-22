class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res=[]
        n=len(nums)
        def backtrack(i,s,curr: List[int]):
            if i >=n or s> target:
                return 
            if s==target:
                res.append(curr.copy())
                return
            curr.append(nums[i])
            backtrack(i,s+nums[i],curr)
            curr.pop()
            backtrack(i+1,s,curr)
        backtrack(0,0,[])
        return res