class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res=[]
        n = len(nums)
        nums.sort()
        def backtracking(i:int,curr,total):
            if total==target:
                res.append(curr.copy())
                return
         
            for j in range(i, len(nums)):
                if total + nums[j] > target:
                    return
                curr.append(nums[j])
                backtracking(j, curr, total + nums[j])
                curr.pop()
            
        backtracking(0,[],0)
        return res
            
