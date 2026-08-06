class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n =len(nums)
        for i in range(len(nums)):
            if nums[i]==val:
                nums[i]= 200
                n-=1
        nums.sort()
        return n