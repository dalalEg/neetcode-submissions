class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)!=n-1:
            return False
        mp={}
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        visited= set()
        stack=[]
        stack.append(0)
        while len(stack):
            node= stack[-1]
            stack.pop()
            if node not in visited:
                visited.add(node)
                for nei in adj[node]:
                    if nei not in visited:
                        stack.append(nei)
        return len(visited)==n

        