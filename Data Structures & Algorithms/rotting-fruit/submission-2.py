class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        res=0
        def bfs(r, c):
            q = deque([(r, c)])
            visit = [[False] * COLS for _ in range(ROWS)]
            visit[r][c] = True
            steps = 0
            while q:
                for _ in range(len(q)):
                    row, col = q.popleft()
                    if grid[row][col] == 2:
                        return steps
                    for dr, dc in directions:
                        nr, nc = row + dr, col + dc
                        if (0 <= nr < ROWS and 0 <= nc < COLS and
                            not visit[nr][nc] and grid[nr][nc] != 0
                        ):
                            visit[nr][nc] = True
                            q.append((nr, nc))
                steps += 1
            return -1

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    curr = bfs(r, c)
                    if curr == -1:
                        return -1 
                    res= max( curr,res)

        return res