import sys
sys.setrecursionlimit(1000000)
class Solution(object):
    def minDistance(self, word1, word2):
        n,m = len(word1),len(word2)
        dp = [[-1 for j in range(m+1)] for i in range(n+1)]
        def dfs(i,j):
            if i>=n:
                return m-j
            if j>=m:
                return n-i
            if dp[i][j]!=-1:
                return dp[i][j]
            if word1[i]==word2[j]:
                dp[i][j]=dfs(i+1,j+1)
                return dp[i][j]
            dp[i][j]=min(dfs(i+1,j),dfs(i,j+1),dfs(i+1,j+1))+1
            return dp[i][j]
        return dfs(0,0)
