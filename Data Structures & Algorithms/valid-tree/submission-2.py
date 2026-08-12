class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)!= n-1:
            return False
        adj=[[]*n for _ in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        visited=set()
        stack=[0]
        while stack :
            curr=stack.pop()
            visited.add(curr)
            for nei in adj[curr]:
                if nei not in visited:
                    stack.append(nei)

        return len(visited)==n