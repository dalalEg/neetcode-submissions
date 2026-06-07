class Solution:
    def maxArea(self, heights: List[int]) -> int:
        res , n = 0 , len(heights)
        for i in range (n):
            for j in range (i+1,n):
                height = min(heights[i],heights[j])
                res = max (height*(j-i),res)
        return res