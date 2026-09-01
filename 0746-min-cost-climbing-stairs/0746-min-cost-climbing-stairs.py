class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0]*(n + 1)
        for p in range(2, n+1):
            dp[p] = min(dp[p-1]+cost[p-1], dp[p-2]+cost[p-2])
        return dp[n]