class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit,currMin=0,prices[0]
        for price in prices:
            profit=max(profit,price-currMin)
            currMin=min(currMin,price)
        return profit
