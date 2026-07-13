# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        left,right =  float("-inf"), float("inf")
        def aux(root,left,right):
            if root == None:
                return True
            if not (left < root.val < right):
                return False

            return aux(root.left,left,root.val) and aux(root.right,root.val,right)
        return aux(root,left,right)