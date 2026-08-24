class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix=res=0
        count={0:1}
        for num in nums:
            prefix+=num
            diff=prefix-k
            if diff in count:
                res+=count[diff]
            count[prefix]=count.get(prefix,0)+1
        return res 