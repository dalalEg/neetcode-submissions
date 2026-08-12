class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = prefix = 0
        prefixSums = { 0 : 1 }

        for num in nums:
            prefix += num
            diff = prefix - k
            if diff in prefixSums:
                res+=prefixSums[diff]

            prefixSums[prefix]=prefixSums.get(prefix,0)+1

        return res