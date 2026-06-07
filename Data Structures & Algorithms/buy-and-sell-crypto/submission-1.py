class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res=0
        s=[]
        prev =prices[0]
        for i in range(1,len(prices)):
            if prices[i]>prev:
                res= max( prices[i]-prev,res)
            else :
                prev=prices[i]
        return res