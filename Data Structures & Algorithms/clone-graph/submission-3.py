"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        visited={}
        def dfs(node):
            if not node:
                return node
            if node.val in visited:
                return visited[node.val]
            temp=Node(node.val)
            visited[node.val]=temp
            for nei in node.neighbors:
                temp.neighbors.append(dfs(nei))
            return temp
        return dfs(node) if node else None