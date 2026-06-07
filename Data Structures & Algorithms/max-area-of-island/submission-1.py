class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])
        maxArea=0
        def dfs(i,j):
            if i<0 or i >=n or j<0 or j>=m:
                return 0
            if grid[i][j]==0:
                return 0
            grid[i][j]=0
            return 1 +dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1)
        for i in range (n):
            for j in range(m):
                if grid[i][j]==1:
                    maxArea =max(maxArea,dfs(i,j))
        print(grid)
        return maxArea

