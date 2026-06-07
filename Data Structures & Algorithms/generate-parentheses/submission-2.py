class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        start="("
        def generateAll(st,openP,closeP,m):
            if len(st) > m or closeP>openP:
                return
            if openP+closeP==m and openP==closeP:
                res.append(st)
                return
            generateAll(st+")",openP,closeP+1,m)
            generateAll(st+"(",openP+1,closeP,m)
        generateAll(start,1,0,n*2);
        return res