class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[amount+1]*(amount+1)
        dp[0]=0
        coins.sort()
        for a in range(1,amount+1):
            for coin in coins:
                if a - coin >= 0:
                    dp[a]=min(dp[a],1+dp[a-coin])
                else:
                    break
        return dp[amount] if dp[amount] != amount + 1 else -1