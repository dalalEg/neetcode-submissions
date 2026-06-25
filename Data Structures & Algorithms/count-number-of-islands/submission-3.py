class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        ROWS, COLS = len(grid), len(grid[0])
        lands = 0
        def dfs (i,j):
            if i<0 or j<0 or i>=ROWS or j>=COLS or grid[i][j]=="0":
                return
            grid[i][j]="0"
            for x,y in directions:
                dfs(i+x,j+y)

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j]=="1":
                    lands+=1
                    dfs(i,j)
        return lands