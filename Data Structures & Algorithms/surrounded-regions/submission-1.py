class Solution:

    def solve(self, board: List[List[str]]) -> None:
        n,m=len(board),len(board[0])
        def dfs(i,j):
            if i < 0 or j <0 or i>=n or j>=m or board[i][j]!="O":
                return 
            board[i][j]="W"
            dfs(i+1,j)
            dfs(i,j+1)
            dfs(i-1,j)
            dfs(i,j-1)
        
        for r in range(n):
            if board[r][0] == "O":
                dfs(r, 0)
            if board[r][m - 1] == "O":
                dfs(r, m - 1)

        for c in range(m):
            if board[0][c] == "O":
                dfs(0, c)
            if board[n - 1][c] == "O":
                dfs(n - 1, c)

        for r in range(n):
            for c in range(m):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "W":
                    board[r][c] = "O"
