class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        n=len(nums)
        def backtrack(i,subset):
            res.append(subset.copy())
            for j in range(i,n):
                if j>i and nums[j]==nums[j-1]:
                    continue
                subset.append(nums[j])
                backtrack(j+1,subset)
                subset.pop()

    
        subset = []
        backtrack(0,subset)
        return res