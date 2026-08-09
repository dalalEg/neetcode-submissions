class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        visited=(n+1)*[False]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        res=0
        for i in range(n):
            if not visited[i]:
                stack=[i]
                while len(stack)>=1 :
                    node=stack.pop()
                    visited[node]=True
                    for nei in adj[node]:
                        if visited[nei]==False:
                            stack.append(nei)
                res+=1
                
        return res