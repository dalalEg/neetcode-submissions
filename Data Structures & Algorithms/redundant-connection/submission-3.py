class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n=len(edges)
        adj=[[] for _ in range(n+1)]
        inDegree=[0]*(n+1)
        for [a,b] in edges:
            adj[a].append(b)
            adj[b].append(a)
            inDegree[a]+=1
            inDegree[b]+=1
        q=deque()
        for i in range(1,n+1):
            if inDegree[i]==1:
                q.append(i)
        while q :
            curr=q.popleft()
            inDegree[curr]-=1
            for nei in adj[curr]:
                inDegree[nei]-=1
                if inDegree[nei]==1:
                        q.append(nei)
        for u, v in reversed(edges):
            if inDegree[u] == 2 and inDegree[v]:
                return [u, v]
        return []