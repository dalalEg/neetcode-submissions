class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m,n=len(board),len(board[0])
        l=len(word)
        visited =[[False]*n for _ in range(m)] 
        def dfs(i,j,w): 
            if w==l :
                return True
            if i>=m or j >=n or i<0 or j<0 or board[i][j]!=word[w] or visited[i][j]:
                return False
            visited[i][j]=True
            res= dfs(i+1,j,w+1) or dfs(i-1,j,w+1) or dfs(i,j+1,w+1) or dfs(i,j-1,w+1)
            visited[i][j]=False
            return res
        for i in range(m):
            for j in range(n):
                if dfs(i,j,0):
                    return True
            
        return False