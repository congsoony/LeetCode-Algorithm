class Solution(object):
    def stoneGame(self, piles):
        n = len(piles)
        dp = [[[-1 for i in range(n)]for j in range(n)]for k in range(2)]
        def dfs(isalice,i,j):
            if i>j:
                return 0
            if dp[isalice][i][j]!=-1:
                return dp[isalice][i][j]
            if isalice ==0:
                dp[isalice][i][j] = max(dfs(1,i+1,j)+piles[i],dfs(1,i,j-1)+piles[j])
                return dp[isalice][i][j]
            dp[isalice][i][j] = min(dfs(0,i+1,j),dfs(0,i,j-1))
            return dp[isalice][i][j]
        total = sum(piles)
        alicescore = dfs(0,0,n-1)
        return alicescore>(total-alicescore)
