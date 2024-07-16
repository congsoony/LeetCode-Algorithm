import sys
sys.setrecursionlimit(1000000)
class Solution(object):
    def knightProbability(self, n, k, row, column):
        dy = [-2,-1,1,2,2,1,-1,-2]
        dx = [1,2,2,1,-1,-2,-2,-1]
        dp=[[[-1 for x in range(k)]for y in range(n)]for z in range(n)]
        def isrange(y,x):
            return 0<=y and y<n and 0<=x and x<n
        def dfs(y,x,h):
            if h>=k:
                return 1
            if dp[y][x][h]!=-1:
                return dp[y][x][h]
            res = 0
            for i in range(8):
                ny =y+dy[i]
                nx =x+dx[i]
                if isrange(ny,nx):
                    res +=dfs(ny,nx,h+1)
            dp[y][x][h]=res
            return res
        
        return float(dfs(row,column,0))/float((8**k))
