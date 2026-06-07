class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = []
        seen = {}
        for i in range(len(nums)):
            goal= target-nums[i]
            if goal in seen.keys():
                res.append(seen.get(goal))
                res.append(i)
                return res
            seen[nums[i]]=i
        return 
        