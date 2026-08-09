class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))
        visited=set()
        pq=[(0,k)]
        res=0
        while pq:
            t,v=heapq.heappop(pq)
            if v in visited:
                continue
            res=t
            visited.add(v)
            for v2,t2 in edges[v]:
                if v2 not in visited:
                    heapq.heappush(pq,(t+t2,v2))

        if len(visited)!=n:
            return -1
        return res