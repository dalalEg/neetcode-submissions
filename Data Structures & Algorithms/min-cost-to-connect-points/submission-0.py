class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        adj=defaultdict(list)
        n = len(points)
        for i in range(n):
            x1,y1=points[i][0],points[i][1]
            for j in range(i+1,n):
                x2,y2=points[j][0],points[j][1]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append([dist, j])
                adj[j].append([dist, i])
        res=0
        visit=set()
        minH=[[0,0]]
        while len(visit)<n:
            cost,i=heapq.heappop(minH)
            if i in visit:
                continue
            visit.add(i)
            res+=cost
            for newCost,j in adj[i]:
                if j not in visit:
                    heapq.heappush(minH,[newCost,j])
        return res