class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        N,M=len(grid),len(grid[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        res=0
        def dfs(i,j):
            if i<0 or j<0 or i>=N or j>=M or grid[i][j]==0:
                return 0
            grid[i][j]=0
            curr=0
            for direction in directions:
                curr+=dfs(i+direction[0],j+direction[1])
            return 1+curr

        for i in range(N):
            for j in range(M):
                if grid[i][j]==1:
                    res=max(dfs(i,j),res)
        return res
