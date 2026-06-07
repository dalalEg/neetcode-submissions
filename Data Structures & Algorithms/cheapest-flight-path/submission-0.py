class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj=defaultdict(list)
        for fromI,toI,priceI in flights:
            adj[fromI].append((toI,priceI))
        q = deque([(0, src, 0)])
        prices= [float("inf")] * n
        while q:
            cst, node, stops = q.popleft()
            if stops > k :
                continue
            for to,p in adj[node]:
                newPrice=cst+p
                if newPrice < prices[to]:
                    prices[to]=newPrice
                    q.append((newPrice, to, stops + 1))
        return prices[dst] if prices[dst] != float("inf") else -1

