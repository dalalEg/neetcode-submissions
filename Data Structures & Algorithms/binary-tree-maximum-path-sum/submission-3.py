# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res=float('-inf')
        def dfs (node,maxV):
            nonlocal res
            if not node :
                return 0
            maxV=max(maxV,node.val)
            l=max(0,dfs(node.left,maxV))
            r=max(0,dfs(node.right,maxV))
            res=max(res,l+r+node.val)
            return max(l,r)+node.val
        dfs(root,res)
        return res