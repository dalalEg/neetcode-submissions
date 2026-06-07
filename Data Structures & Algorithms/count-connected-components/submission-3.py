class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        visit = [False] * n
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        res=0
        def dfs(i):
            if visit[i]:
                return
            visit[i]=True
            for nei in adj[i]:
                dfs(nei)
        for i in range(n):
            if visit[i]:
                continue
            else:
                dfs(i)
                res+=1
        return res