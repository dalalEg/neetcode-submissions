class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res,n= float('inf'),len(nums)
        l,r=0,0
        curr=0
        for r in range(n):
            curr+=nums[r]
            while curr >=target and l<=r: 
                res=min(res,r-l+1)
                curr -= nums[l]
                l+=1
            
        return res if res !=  float('inf') else 0