class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        n=len(piles)
        def check(k):
            t,i=0,0
            while t <= h and i <n:
                t+=math.ceil(float(piles[i]) / k)
                i=i+1
            return t<=h

        l,r=1,max(piles)
        while l <= r:
            m = (r+l)//2
            if check(m):
                r=m-1
            else:
                l=m+1
        return l
