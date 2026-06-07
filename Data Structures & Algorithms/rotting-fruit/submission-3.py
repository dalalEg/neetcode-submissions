class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = collections.deque()
        fresh = 0
        time = 0
        m,n=len(grid),len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    fresh+=1
                if grid[i][j]==2:
                    q.append((i,j))
        direction=[[1,0],[-1,0],[0,1],[0,-1]]
        while fresh > 0 and q:
            length = len(q)
            for i in range(length):
                r, c = q.popleft()
                for dr, dc in direction:
                    newr,newc=r+dr,c+dc
                    if newr>=0 and newr<m and newc>=0 and newc<n and grid[newr][newc]==1:
                        fresh-=1
                        grid[newr][newc]=2
                        q.append((newr,newc))
            time+=1
        return time if fresh==0 else -1
            




        