class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res=[]
        def combination(i,curr):
            if  len(curr)==k:
                res.append(curr.copy())
                return
            if i > n :
                return
            curr.append(i)
            combination(i+1,curr)
            curr.pop()
            combination(i+1,curr)
        combination(1,[])
        return res