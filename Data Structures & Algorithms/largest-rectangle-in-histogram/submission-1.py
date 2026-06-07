from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        left = [0] * n
        right = [0] * n

        # Left pass
        stackLeft = []
        for i in range(n):
            while stackLeft and heights[stackLeft[-1]] >= heights[i]:
                stackLeft.pop()
            # if stack empty → no smaller element, so extend all the way
            left[i] = i if not stackLeft else i - stackLeft[-1] - 1
            stackLeft.append(i)

        # Right pass
        stackRight = []
        for i in range(n - 1, -1, -1):
            while stackRight and heights[stackRight[-1]] >= heights[i]:
                stackRight.pop()
            # if stack empty → no smaller element, so extend all the way
            right[i] = (n - 1 - i) if not stackRight else stackRight[-1] - i - 1
            stackRight.append(i)

        # Compute max area
        res = 0
        for i in range(n):
            width = left[i] + right[i] + 1
            res = max(res, heights[i] * width)

        return res
