class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m,n=len(heights),len(heights[0]) 
        res=[]
        pac, atl = set(), set()
        def dfs(i,j,visited,prev):
            if ((i,j) in visited or i<0 or j<0 or j==n or i==m or heights[i][j] < prev):
                return False
            visited.add((i,j))
            dfs(i-1,j,visited,heights[i][j])
            dfs(i+1,j,visited,heights[i][j])
            dfs(i,j-1,visited,heights[i][j])
            dfs(i,j+1,visited,heights[i][j])

        for i in range(m):
            dfs(i,0,pac,heights[i][0])
            dfs(i,n-1,atl,heights[i][n-1]) 
        for j in range(n):
            dfs(0,j,pac,heights[0][j])
            dfs(m-1,j,atl,heights[m-1][j])
        for i in range(m):
            for j in range(n):
                if (i,j) in atl and (i,j) in pac:
                    res.append([i,j])
        return res