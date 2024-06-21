class Solution(object):
    def minCostClimbingStairs(self, cost):
        global dp,inf
        inf = 1000000000000
        dp=[inf]*len(cost)
        return min(self.dfs(0,cost),self.dfs(1,cost))
    def dfs(self,cur,cost):
        global dp,inf
        if cur>=len(dp):
            return 0
        if dp[cur] !=inf:
            return dp[cur]
        dp[cur] = min(self.dfs(cur+1,cost), self.dfs(cur+2,cost)) +cost[cur]
        return dp[cur]
