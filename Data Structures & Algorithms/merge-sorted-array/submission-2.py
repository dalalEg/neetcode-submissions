class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        if m==0:
            nums1[:] = nums2
            return
        nums1_copy = nums1[:m]
        i,i1,i2=0,0,0
        while i<n+m :
            if  i2>=n or (i1<m and nums1_copy[i1]< nums2[i2]):
                nums1[i]=nums1_copy[i1]
                i1+=1
            else:
                nums1[i]=nums2[i2]
                i2+=1
            i+=1
  
