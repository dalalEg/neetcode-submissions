class Solution:
    def maxArea(self, heights: List[int]) -> int:
        res , r = 0 , len(heights)-1
        l=0
        while l < r:
            h=min(heights[r],heights[l])
            res = max (h*(r-l),res)
            if heights[l] <= heights[r]:
                l += 1
            else:
                r -= 1
        return res