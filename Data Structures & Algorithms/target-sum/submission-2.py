class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        total = sum(nums)

        # possible sums are from -total to +total
        offset = total
        dp = [[0] * (2 * total + 1) for _ in range(n + 1)]

        # sum 0 can be made in one way before using any numbers
        dp[0][offset] = 1

        for i in range(n):
            for s in range(-total, total + 1):
                ways = dp[i][s + offset]

                if ways == 0:
                    continue

                # choose +
                dp[i + 1][s + nums[i] + offset] += ways

                # choose -
                dp[i + 1][s - nums[i] + offset] += ways

        if target < -total or target > total:
            return 0

        return dp[n][target + offset]