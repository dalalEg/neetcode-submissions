class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))

        minHeap = [(0, k)]
        visit = set()
        t = 0
        while minHeap:
            t1,v1=heapq.heappop(minHeap)
            if v1 in visit:
                continue
            t=t1
            visit.add(v1)
            for edge,time in edges[v1]:
                if  edge not in visit:
                    heapq.heappush(minHeap,(time+t1,edge))
        return t if len(visit)==n else -1 