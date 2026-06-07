class Solution:

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        m = max(piles)
        l,r=1,m
        res =r
        while l<=r:
            mid = l+(r-l)//2
            currT=0
            for pile in piles:
                currT += math.ceil(float(pile) / mid)
            if currT<=h:
                res=min(res, mid)
                r= mid-1
            else:
                l=mid+1
        return res