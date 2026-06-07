class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP,currMin=0,prices[0]
        for price in prices:
            maxP=max(maxP,price-currMin)
            currMin=min(currMin, price)
        return maxP