class Solution:
    def countBits(self, n: int) -> List[int]:
        res=[0]*(n+1)
        for j in range(n+1):
            ones=0
            for i in range(32):
                if (1<<i) & j:
                    ones+=1
            res[j]=ones  
        return res