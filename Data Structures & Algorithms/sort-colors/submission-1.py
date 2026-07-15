class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero,one,two=0,0,0
        for num in nums:
            zero = zero + 1  if num==0 else zero
            one = one + 1  if num==1 else one
            two = two + 1  if num==2 else two
        i =0
        for j in range(zero):
            nums[i]=0
            i +=1
        for j in range(one):
            nums[i]=1
            i +=1
        for j in range(two):
            nums[i]=2
            i +=1

        