class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        res=[]
        m,n=len(heights),len(heights[0])
        pacific,atlantic=set(),set()
        def dfs(i,j,curr,prev):
            if (i,j) in curr or  i<0 or j <0 or j>=n or i >=m or prev> heights[i][j]:
                return 
            curr.add((i,j))
            tmp=heights[i][j]
            dfs(i-1,j,curr,tmp)
            dfs(i+1,j,curr,tmp)
            dfs(i,j-1,curr,tmp)
            dfs(i,j+1,curr,tmp)


        for j in range(n):
            dfs(0,j,pacific,-1)
            dfs(m-1,j,atlantic,-1)
        for i in range(m):
            dfs(i,0,pacific,-1) 
            dfs(i,n-1,atlantic,-1)
        for i in range(m):
            for j in range(n):
                if (i,j) in pacific and (i,j) in atlantic:
                    res.append([i,j])
        return res
        