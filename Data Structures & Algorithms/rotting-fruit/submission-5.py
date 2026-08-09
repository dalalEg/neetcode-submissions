class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        t=0
        fresh=0
        q=deque()
        m,n=len(grid),len(grid[0])
        for i in range(m):
            for j in range (n):
                if grid[i][j]==1:
                    fresh+=1
                elif grid[i][j]==2:
                    q.append((i,j))
        directions={(1,0),(-1,0),(0,1),(0,-1)}
        while fresh >0 and q:
            size=len(q)
            t=t+1
            for i in range(size):
                (x,y)=q.popleft()
                for (x1,y1) in directions:
                    u,v=x+x1 , y+y1 
                    if u< m and u>=0 and 0<=v and v< n and grid[u][v] == 1:
                        fresh-=1
                        q.append((u,v))
                        grid[u][v]=2
        return t if fresh ==0 else -1