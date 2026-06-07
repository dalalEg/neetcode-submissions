class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        m,n=len(grid),len(grid[0])
        INF=2147483647 
        q=collections.deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j]==0:
                    q.append((i,j))
        dist=1
        directions=[[1,0],[0,1],[-1,0],[0,-1]]
        while q:
            size=len(q)
            for i in range(size):
                r,c=q.popleft()
                for nr,nc in directions:
                    newr,newc=r+nr,c+nc
                    if 0<=newr<m  and 0<=newc<n and grid[newr][newc]==INF:
                        grid[newr][newc]=dist
                        q.append((newr,newc))
            dist+=1