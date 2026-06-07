class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))
        minHeap=[(0,k)]
        visited=set()
        t=0
        while len(minHeap)>0:
            t1,v1,=heapq.heappop(minHeap)
            if v1 in visited:
                continue
            t=t1
            visited.add(v1)
            for v2,t2 in edges[v1]:
                if  v2 not in visited:
                    heapq.heappush(minHeap,[t1+t2,v2])
        return t if len(visited)==n else -1 