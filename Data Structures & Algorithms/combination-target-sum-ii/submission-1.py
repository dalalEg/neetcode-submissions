class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        res=[]
        nums.sort()
        def backtrack(i,subset):
          
            if sum(subset)== target:
                res.append(subset.copy())
                return
            if sum(subset)> target or i>=len(nums):
                return 
            subset.append(nums[i])
            backtrack(i+1,subset)
            subset.pop()
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            backtrack(i + 1, subset)
            
        backtrack(0,[])
        return res