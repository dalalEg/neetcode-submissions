class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res=[]
        n = len(nums)
        def backtracking(i:int,curr):
            if i >= n or sum(curr)> target:
                return
            if sum(curr)==target:
                res.append(curr.copy())
                return
         
            curr.append(nums[i])
            backtracking(i,curr)
            curr.pop()
            backtracking(i+1,curr)
            
        backtracking(0,[])
        return res
            
