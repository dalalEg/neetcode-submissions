class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap=[]
        res=[]
        for point in points:
          dist= point[0]*point[0]+point[1]*point[1]
          heapq.heappush(heap,[-1*dist,point])
          if len(heap)>k:
              heapq.heappop(heap)
        while heap:
          dist, a = heapq.heappop(heap)
          res.append(a)
        
        return res