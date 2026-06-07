class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        ROWS, COLS = len(grid), len(grid[0])
        islands = 0
        def bfs (i,j):
            if i < 0 or j < 0 or i>= ROWS or j >= COLS or grid[i][j]=="0":
                return 
            grid[i][j]="0"
            for direction in directions:
                bfs(i+direction[0],j+direction[1])
            
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j]=="1":
                    islands+=1
                    bfs(i,j)
        return islands
            