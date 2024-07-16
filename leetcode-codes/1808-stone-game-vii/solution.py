import sys
sys.setrecursionlimit(1000000)
class Solution(object):
    def stoneGameVII(self, stones):
        n = len(stones)
        t= 0 if n%2==0 else 1

        prefix = [0]*(n+1)
        dp = [[-1 for j in range(n+1)] for i in range(n+1)]
        for i in range(1,n+1):prefix[i]=prefix[i-1]+stones[i-1]
        
        def dfs(i,j):
            if i>j:return 0
            if dp[i][j]!= -1:
                return dp[i][j]
            if (i+j+t)%2==1:
                _max = max(dfs(i+1,j)+prefix[j]-prefix[i] , dfs(i,j-1)+prefix[j-1]-prefix[i-1])
                dp[i][j] = _max
                return _max
            _min = int(1e10)
            _min = min(dfs(i+1,j)-(prefix[j]-prefix[i]),dfs(i,j-1)-(prefix[j-1]-prefix[i-1]))
            dp[i][j]=_min
            return _min
        return dfs(1,n)
