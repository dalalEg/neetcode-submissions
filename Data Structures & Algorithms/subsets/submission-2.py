class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []
        n=len(nums)
        def backtrack(i,subset):
            if i >=n:
                res.append(subset.copy())
                return
            subset.append(nums[i])
            backtrack(i+1,subset)
            subset.pop()
            backtrack(i+1,subset)

        backtrack(0,subset)
        return res