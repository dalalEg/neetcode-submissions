class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap=[]
        for stone in stones:
            heapq.heappush(heap,-stone)
        while len(heap)>=2:
            first,second=-1*heapq.heappop(heap),-1*heapq.heappop(heap)
            if first != second:
                heapq.heappush(heap,-first+second)

        return 0 if  len(heap)==0 else -1* heapq.heappop(heap)
               
