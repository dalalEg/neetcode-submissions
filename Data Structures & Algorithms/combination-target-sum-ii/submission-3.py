class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res=[]
        n = len(candidates)
        def backtracking(i,curr):
            if sum(curr) == target:
                res.append(curr.copy())
                return
            if sum(curr) > target or i>=n:
                return
            curr.append(candidates[i])
            backtracking(i+1, curr)
            curr.pop()
            while i + 1 < n and candidates[i] == candidates[i+1]:
                i += 1
            backtracking(i + 1, curr)
                    

        backtracking(0,[])
        return res