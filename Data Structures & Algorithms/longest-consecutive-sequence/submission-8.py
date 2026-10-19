class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        s=set(nums)
        res,pre=0,next(iter(s))
        count=1
        for ss in s:
            if (ss-1) not in s:
                l=1
                while ( ss+ l) in s:
                    l+=1
                res=max(l,res)
            
        return max(res,count)