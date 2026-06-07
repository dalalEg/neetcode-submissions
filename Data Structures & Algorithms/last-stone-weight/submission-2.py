class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap=[]
        for stone in stones:
            heapq.heappush(heap,-1*stone)
        while len(heap)>=2:
            x,y=heapq.heappop(heap),heapq.heappop(heap)
            if x==y:
                continue
            else:
                x,y=-1*x,-1*y
                heapq.heappush(heap,-1*(x-y))
        heap.append(0)
        return abs(heap[0])