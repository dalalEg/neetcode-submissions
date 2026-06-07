from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        def order(curr, top, bottom, left, right):
            if top > bottom or left > right:
                return
            # Traverse top row
            for j in range(left, right + 1):
                curr.append(matrix[top][j])
            # Traverse right column
            for i in range(top + 1, bottom + 1):
                curr.append(matrix[i][right])
            # Traverse bottom row (if not same as top)
            if top != bottom:
                for j in range(right - 1, left - 1, -1):
                    curr.append(matrix[bottom][j])
            # Traverse left column (if not same as right)
            if left != right:
                for i in range(bottom - 1, top, -1):
                    curr.append(matrix[i][left])
            # Recurse inward
            order(curr, top + 1, bottom - 1, left + 1, right - 1)

        if not matrix or not matrix[0]:
            return []
        curr = []
        order(curr, 0, len(matrix) - 1, 0, len(matrix[0]) - 1)
        return curr